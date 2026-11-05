#!/usr/bin/env python3
"""Regression tests proving that the AST verifier detects structural errors."""

from __future__ import annotations

import copy
from pathlib import Path
import unittest

from ast_cases import AstSource
from ast_expected import (
    case_24,
    case_25,
    case_44,
    declaration,
    id_list,
    node,
    type_,
)
from verify_ast import AstPrintParser, compare, make_test_case, tokenize


def recursive_struct_program():
    struct_type = type_("T_STRUCT")
    pointer_type = type_("T_POINTER", element_type=struct_type)
    field = declaration("next", "ID_FIELD", 0, pointer_type)
    struct_type["field"] = id_list(field)
    root = declaration(
        "root", "ID_VAR", 0, struct_type, specifier="S_AUTO"
    )
    return node("N_PROGRAM", clink=id_list(root))


def return_add(program):
    function = program["clink"]
    body = function["type"]["expr"]
    return body["rlink"]["llink"]["clink"]


class ComparatorRegressionTests(unittest.TestCase):
    def assert_rejected(self, expected, actual):
        self.assertTrue(compare(expected, actual), "corrupted AST was accepted")

    def test_normal_ast_passes(self):
        expected = case_25()
        self.assertEqual(compare(expected, copy.deepcopy(expected)), [])

    def test_node_kind_error_fails(self):
        expected = case_25()
        actual = copy.deepcopy(expected)
        return_add(actual)["name"] = "N_EXP_SUB"
        self.assert_rejected(expected, actual)

    def test_identifier_target_error_fails(self):
        expected = case_44()
        actual = copy.deepcopy(expected)
        body = actual["clink"]["link"]["type"]["expr"]
        second_statement = body["rlink"]["rlink"]
        inner_x = second_statement["llink"]["llink"]
        return_statement = second_statement["rlink"]["llink"]
        return_statement["clink"]["clink"]["target"] = inner_x
        self.assert_rejected(expected, actual)

    def test_declaration_order_error_fails(self):
        expected = case_24()
        actual = copy.deepcopy(expected)
        add = actual["clink"]
        main = add["link"]
        actual["clink"] = main
        main["link"] = add
        add["link"] = None
        self.assert_rejected(expected, actual)

    def test_nil_nodes_require_null_children(self):
        for nil_name in ("N_STMT_LIST_NIL", "N_ARG_LIST_NIL"):
            with self.subTest(nil_name=nil_name):
                expected = node(nil_name)
                actual = copy.deepcopy(expected)
                actual["llink"] = node("N_STMT_EMPTY")
                self.assert_rejected(expected, actual)

    def test_visible_specifier_error_fails(self):
        expected = case_24()
        actual = copy.deepcopy(expected)
        actual["clink"]["specifier"] = "S_NULL"
        self.assert_rejected(expected, actual)

    def test_visible_initializer_error_fails(self):
        expected = case_24()
        actual = copy.deepcopy(expected)
        actual["clink"]["init"] = node("N_INIT_LIST_NIL")
        self.assert_rejected(expected, actual)

    def test_type_kind_error_fails(self):
        expected = case_24()
        actual = copy.deepcopy(expected)
        actual["clink"]["type"]["element_type"]["kind"] = "T_FLOAT"
        self.assert_rejected(expected, actual)

    def test_constant_value_error_fails(self):
        expected = case_24()
        actual = copy.deepcopy(expected)
        main_body = actual["clink"]["link"]["type"]["expr"]
        main_body["rlink"]["llink"]["clink"]["clink"] = 1
        self.assert_rejected(expected, actual)

    def test_recursive_shared_type_passes(self):
        expected = recursive_struct_program()
        self.assertEqual(compare(expected, recursive_struct_program()), [])

    def test_broken_recursive_type_sharing_fails(self):
        expected = recursive_struct_program()
        actual = recursive_struct_program()
        clone = recursive_struct_program()["clink"]["type"]
        pointer = actual["clink"]["type"]["field"]["type"]
        pointer["element_type"] = clone
        self.assert_rejected(expected, actual)


class AstPrintParserRegressionTests(unittest.TestCase):
    def test_done_resolves_recursive_type(self):
        output = """\
=======  syntax tree  ==========
N_PROGRAM (00000000,0)
|  (ID="root") TYPE:00000010 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  STRUCT
|  |  |  |  FIELD
|  |  |  |  |  (ID="next") TYPE:00000020 KIND:FIELD SPEC=NULL LEV=0 VAL=0 ADDR=0
|  |  |  |  |  |  TYPE
|  |  |  |  |  |  |  POINTER
|  |  |  |  |  |  |  |  ELEMENT_TYPE
|  |  |  |  |  |  |  |  |  (DONE:00000010)
"""
        actual = AstPrintParser(tokenize(output)).parse()
        self.assertEqual(compare(recursive_struct_program(), actual), [])

    def test_done_preserves_shared_non_recursive_type(self):
        output = """\
=======  syntax tree  ==========
N_PROGRAM (00000000,0)
|  (ID="a") TYPE:00000010 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  STRUCT
|  |  |  |  FIELD
|  (ID="b") TYPE:00000010 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  (DONE:00000010)
"""
        shared_type = type_("T_STRUCT")
        a = declaration("a", "ID_VAR", 0, shared_type, specifier="S_AUTO")
        b = declaration("b", "ID_VAR", 0, shared_type, specifier="S_AUTO")
        expected = node("N_PROGRAM", clink=id_list(a, b))
        actual = AstPrintParser(tokenize(output)).parse()
        self.assertEqual(compare(expected, actual), [])

    def test_done_resolves_uniquely_nested_first_appearance(self):
        output = """\
=======  syntax tree  ==========
N_PROGRAM (00000000,0)
|  (ID="a") TYPE:00000010 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  POINTER
|  |  |  |  ELEMENT_TYPE
|  |  |  |  |  STRUCT
|  |  |  |  |  |  FIELD
|  (ID="b") TYPE:00000020 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  POINTER
|  |  |  |  ELEMENT_TYPE
|  |  |  |  |  (DONE:00000030)
"""
        shared_type = type_("T_STRUCT")
        first_pointer = type_("T_POINTER", element_type=shared_type)
        second_pointer = type_("T_POINTER", element_type=shared_type)
        a = declaration("a", "ID_VAR", 0, first_pointer, specifier="S_AUTO")
        b = declaration("b", "ID_VAR", 0, second_pointer, specifier="S_AUTO")
        expected = node("N_PROGRAM", clink=id_list(a, b))
        actual = AstPrintParser(tokenize(output)).parse()
        self.assertEqual(compare(expected, actual), [])

    def test_unimplemented_case_is_skip_candidate(self):
        source = AstSource("01", "integer", Path("tests/ast/01_integer.c"))
        self.assertIsNone(make_test_case(source).expectation)


if __name__ == "__main__":
    unittest.main()

