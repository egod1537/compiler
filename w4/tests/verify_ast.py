#!/usr/bin/env python3
"""Build the parser and compare AST_PRINT output with hand-written expectations."""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import re
import subprocess
from dataclasses import dataclass
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from ast_cases import (
    AstSource,
    CaseSelectionError,
    choose_numbered_source,
    discover_ast_sources,
)
from ast_expected import CASES
from parser_build import ParserBuildError, build_parser


ROOT = Path(__file__).resolve().parents[1]


class VerificationError(Exception):
    pass


@dataclass
class Token:
    kind: str
    value: Any
    line: int
    depth: int


@dataclass
class Difference:
    path: str
    expected: Any
    actual: Any


@dataclass
class TestCase:
    number: str
    slug: str
    source: Path
    expectation: Optional[Callable[[], Dict[str, Any]]]


@dataclass
class CaseResult:
    case: TestCase
    status: str
    expected: Optional[Dict[str, Any]] = None
    actual: Optional[Dict[str, Any]] = None
    differences: Optional[List[Difference]] = None


NODE_RE = re.compile(r"^(N_[A-Z0-9_]+)\s+\(([^,]+),(-?\d+)\)$")
ID_RE = re.compile(
    r'^\(ID="([^"]*)"\)\s+TYPE:(\S+)\s+KIND:([A-Z_]+)\s+'
    r'SPEC=([A-Z_]+)\s+LEV=(-?\d+)\s+VAL=(-?\d+)\s+ADDR=(-?\d+)'
)
DONE_RE = re.compile(r"^\(DONE:([^\)]+)\)$")
INTEGER_RE = re.compile(r"^-?\d+$")
LABELS = {"PARAMETER", "TYPE", "BODY", "ELEMENT_TYPE", "INDEX", "FIELD", "ENUMERATORS", "INIT"}
TYPE_WORDS = {
    "FUNCTION": "T_FUNC",
    "POINTER": "T_POINTER",
    "ARRAY": "T_ARRAY",
    "STRUCT": "T_STRUCT",
    "UNION": "T_UNION",
    "ENUM": "T_ENUM",
    "NULL": "T_NULL",
    "VOID": "T_VOID",
}


def parse_address(text: str) -> Optional[int]:
    value = text.strip().lower()
    if value in {"(nil)", "nil", "null", "0x0"} or set(value) == {"0"}:
        return None
    if value.startswith("0x"):
        value = value[2:]
    return int(value, 16)


def _content(line: str) -> Tuple[int, str]:
    text = line.lstrip()
    depth = 0
    while text.startswith("|  "):
        depth += 1
        text = text[3:]
    return depth, text.strip()


def tokenize(output: str) -> List[Token]:
    marker = "=======  syntax tree  =========="
    marker_at = output.find(marker)
    if marker_at < 0:
        raise VerificationError("AST_PRINT header was not found in compiler output")

    tree_output = output[marker_at + len(marker) :]
    # print.c omits a newline for these two built-in type spellings.
    tree_output = re.sub(r"(\((?:void|null)\))(?=\|)", r"\1\n", tree_output)

    tokens: List[Token] = []
    for line_number, raw_line in enumerate(tree_output.splitlines(), start=1):
        depth, content = _content(raw_line)
        if not content:
            continue

        node_match = NODE_RE.match(content)
        if node_match:
            tokens.append(
                Token(
                    "NODE",
                    {
                        "name": node_match.group(1),
                        "type_address": parse_address(node_match.group(2)),
                        "value": int(node_match.group(3)),
                    },
                    line_number,
                    depth,
                )
            )
            continue

        id_match = ID_RE.match(content)
        if id_match:
            tokens.append(
                Token(
                    "ID",
                    {
                        "name": id_match.group(1),
                        "type_address": parse_address(id_match.group(2)),
                        "kind": "ID_" + id_match.group(3),
                        "specifier": "S_" + id_match.group(4),
                        "level": int(id_match.group(5)),
                        "value": int(id_match.group(6)),
                        "address": int(id_match.group(7)),
                    },
                    line_number,
                    depth,
                )
            )
            continue

        if content in LABELS:
            tokens.append(Token("LABEL", content, line_number, depth))
            continue

        if content == "(int)":
            tokens.append(Token("TYPE_KIND", "T_INT", line_number, depth))
            continue
        if content == "(float)":
            tokens.append(Token("TYPE_KIND", "T_FLOAT", line_number, depth))
            continue
        if content.startswith("(char ") and content.endswith(")"):
            tokens.append(Token("TYPE_KIND", "T_CHAR", line_number, depth))
            continue
        if content == "(void)":
            tokens.append(Token("TYPE_KIND", "T_VOID", line_number, depth))
            continue
        if content == "(null)":
            tokens.append(Token("TYPE_KIND", "T_NULL", line_number, depth))
            continue
        done_match = DONE_RE.match(content)
        if done_match:
            tokens.append(
                Token(
                    "TYPE_REF",
                    parse_address(done_match.group(1)),
                    line_number,
                    depth,
                )
            )
            continue
        if content in TYPE_WORDS:
            tokens.append(Token("TYPE_KIND", TYPE_WORDS[content], line_number, depth))
            continue
        if content == "(none)":
            tokens.append(Token("NONE", None, line_number, depth))
            continue
        if INTEGER_RE.match(content):
            tokens.append(Token("INTEGER", int(content), line_number, depth))
            continue

        raise VerificationError(
            f"unrecognized AST_PRINT content on tree line {line_number}: {content!r}"
        )

    return tokens


class AstPrintParser:
    BINARY_EXPRESSIONS = {
        "N_EXP_ARRAY",
        "N_EXP_MUL",
        "N_EXP_DIV",
        "N_EXP_MOD",
        "N_EXP_ADD",
        "N_EXP_SUB",
        "N_EXP_LSS",
        "N_EXP_GTR",
        "N_EXP_LEQ",
        "N_EXP_GEQ",
        "N_EXP_NEQ",
        "N_EXP_EQL",
        "N_EXP_AND",
        "N_EXP_OR",
        "N_EXP_ASSIGN",
    }
    UNARY_EXPRESSIONS = {
        "N_EXP_POST_INC",
        "N_EXP_POST_DEC",
        "N_EXP_PRE_INC",
        "N_EXP_PRE_DEC",
        "N_EXP_AMP",
        "N_EXP_STAR",
        "N_EXP_NOT",
        "N_EXP_PLUS",
        "N_EXP_MINUS",
        "N_EXP_SIZE_EXP",
    }

    def __init__(self, tokens: Sequence[Token]):
        self.tokens = tokens
        self.position = 0
        self.types_by_address: Dict[int, Dict[str, Any]] = {}
        self.builtin_types: Dict[str, Dict[str, Any]] = {}
        self.unaddressed_types: List[Dict[str, Any]] = []
        self.scopes: List[List[Dict[str, Any]]] = [[]]

    def peek(
        self,
        kind: Optional[str] = None,
        value: Any = None,
        depth: Optional[int] = None,
    ) -> bool:
        if self.position >= len(self.tokens):
            return False
        token = self.tokens[self.position]
        return (
            (kind is None or token.kind == kind)
            and (value is None or token.value == value)
            and (depth is None or token.depth == depth)
        )

    def take(
        self, kind: str, value: Any = None, depth: Optional[int] = None
    ) -> Token:
        if self.position >= len(self.tokens):
            raise VerificationError(f"unexpected end of AST_PRINT output; expected {value or kind}")
        token = self.tokens[self.position]
        if (
            token.kind != kind
            or (value is not None and token.value != value)
            or (depth is not None and token.depth != depth)
        ):
            raise VerificationError(
                f"tree line {token.line}: expected {value or kind} at depth {depth}, "
                f"got {token.value!r} at depth {token.depth}"
            )
        self.position += 1
        return token

    def type_at(self, address: Optional[int]) -> Optional[Dict[str, Any]]:
        if address is None:
            return None
        if address not in self.types_by_address:
            self.types_by_address[address] = self.make_type(None)
        return self.types_by_address[address]

    def bind_type_address(
        self, type_object: Dict[str, Any], address: Optional[int]
    ) -> Dict[str, Any]:
        if address is None:
            return type_object
        existing = self.types_by_address.get(address)
        if existing is None:
            self.types_by_address[address] = type_object
            return type_object
        return existing

    def make_node(
        self,
        token: Token,
        llink: Any = None,
        clink: Any = None,
        rlink: Any = None,
    ) -> Dict[str, Any]:
        return {
            "class": "A_NODE",
            "name": token.value["name"],
            "type": self.type_at(token.value["type_address"]),
            "value": token.value["value"],
            "llink": llink,
            "clink": clink,
            "rlink": rlink,
        }

    @staticmethod
    def make_type(
        kind: Optional[str],
        element_type: Any = None,
        field: Any = None,
        expr: Any = None,
    ) -> Dict[str, Any]:
        return {
            "class": "A_TYPE",
            "kind": kind,
            "element_type": element_type,
            "field": field,
            "expr": expr,
        }

    def parse(self) -> Dict[str, Any]:
        root = self.take("NODE", depth=0)
        if root.value["name"] != "N_PROGRAM":
            raise VerificationError(f"expected N_PROGRAM, got {root.value['name']}")
        program = self.make_node(root, clink=self.parse_id_list(1, register_scope=True))
        if self.position != len(self.tokens):
            token = self.tokens[self.position]
            raise VerificationError(
                f"tree line {token.line}: unexpected trailing value {token.value!r}"
            )
        unresolved = [
            address
            for address, type_object in self.types_by_address.items()
            if type_object.get("kind") is None
        ]
        if unresolved:
            rendered = ", ".join(hex(address) for address in unresolved)
            raise VerificationError(f"DONE referenced unresolved type address(es): {rendered}")
        return program

    def parse_id_list(
        self, depth: int, *, register_scope: bool
    ) -> Optional[Dict[str, Any]]:
        items: List[Dict[str, Any]] = []
        while self.peek("ID", depth=depth):
            items.append(self.parse_declaration(depth, register_scope=register_scope))

        head: Optional[Dict[str, Any]] = None
        for item in reversed(items):
            item["link"] = head
            head = item
        return head

    def parse_declaration(
        self, depth: int, *, register_scope: bool
    ) -> Dict[str, Any]:
        printed = self.take("ID", depth=depth).value
        declaration = {
            "class": "A_ID",
            "name": printed["name"],
            "kind": printed["kind"],
            "level": printed["level"],
            "specifier": printed["specifier"],
            "value": printed["value"],
            "address": printed["address"],
            "type": self.type_at(printed["type_address"]),
            "init": None,
            "link": None,
        }
        if register_scope:
            self.scopes[-1].append(declaration)

        if self.peek("LABEL", "TYPE", depth + 1):
            self.take("LABEL", "TYPE", depth + 1)
            declaration["type"] = self.parse_type(
                depth + 2, printed["type_address"]
            )
        elif printed["type_address"] is not None:
            raise VerificationError(
                f"identifier {printed['name']!r} has a type address but no TYPE output"
            )

        if self.peek("LABEL", "INIT", depth + 1):
            self.take("LABEL", "INIT", depth + 1)
            if declaration["kind"] == "ID_ENUM_LITERAL":
                declaration["init"] = self.parse_expression(depth + 2)
            else:
                declaration["init"] = self.parse_initializer(depth + 2)
        return declaration

    def parse_reference(self, depth: int) -> Dict[str, Any]:
        printed = self.take("ID", depth=depth).value
        reference = {
            "class": "A_ID_REF",
            "name": printed["name"],
            "kind": printed["kind"],
            "level": printed["level"],
            "specifier": printed["specifier"],
            "value": printed["value"],
            "address": printed["address"],
            "type": self.type_at(printed["type_address"]),
            "target": None,
        }
        reference["target"] = self.resolve_reference(reference)
        return reference

    def resolve_reference(self, reference: Dict[str, Any]) -> Optional[Dict[str, Any]]:
        """Resolve an A_ID reference only when printed lexical evidence is unique.

        print.c does not emit A_ID object addresses, so ambiguous matches must stay
        unresolved instead of being guessed.
        """
        visible_fields = (
            "name",
            "kind",
            "level",
            "specifier",
            "value",
            "address",
        )
        for scope in reversed(self.scopes):
            named = [item for item in scope if item["name"] == reference["name"]]
            if not named:
                continue
            matches = [
                item
                for item in named
                if all(item[field] == reference[field] for field in visible_fields)
                and item["type"] is reference["type"]
            ]
            return matches[0] if len(matches) == 1 else None
        return None

    def parse_type(
        self, depth: int, address_hint: Optional[int] = None
    ) -> Dict[str, Any]:
        if self.peek("TYPE_REF", depth=depth):
            reference = self.take("TYPE_REF", depth=depth).value
            if reference is None:
                raise VerificationError("DONE contains a null type address")
            if reference not in self.types_by_address:
                if len(self.unaddressed_types) == 1:
                    candidate = self.unaddressed_types.pop()
                    self.types_by_address[reference] = candidate
                else:
                    self.type_at(reference)
            return self.type_at(reference)

        kind = self.take("TYPE_KIND", depth=depth).value
        if kind in {"T_INT", "T_FLOAT", "T_CHAR", "T_VOID", "T_NULL"}:
            type_object = self.builtin_types.get(kind)
            if type_object is None:
                type_object = self.type_at(address_hint) or self.make_type(kind)
                type_object["kind"] = kind
                self.builtin_types[kind] = type_object
            bound = self.bind_type_address(type_object, address_hint)
            if bound.get("kind") is None:
                bound["kind"] = kind
            self.builtin_types[kind] = bound
            return bound

        type_object = self.type_at(address_hint) or self.make_type(kind)
        if address_hint is None:
            self.unaddressed_types.append(type_object)
        if type_object.get("kind") not in {None, kind}:
            raise VerificationError("one type address was printed with conflicting kinds")
        type_object["kind"] = kind

        if kind == "T_FUNC":
            self.take("LABEL", "PARAMETER", depth + 1)
            self.scopes.append([])
            try:
                type_object["field"] = self.parse_id_list(
                    depth + 2, register_scope=True
                )
                self.take("LABEL", "TYPE", depth + 1)
                type_object["element_type"] = self.parse_type(depth + 2)
                if self.peek("LABEL", "BODY", depth + 1):
                    self.take("LABEL", "BODY", depth + 1)
                    type_object["expr"] = self.parse_statement(
                        depth + 2, function_body=True
                    )
            finally:
                self.scopes.pop()
            return type_object

        if kind == "T_POINTER":
            self.take("LABEL", "ELEMENT_TYPE", depth + 1)
            type_object["element_type"] = self.parse_type(depth + 2)
            return type_object

        if kind == "T_ARRAY":
            self.take("LABEL", "INDEX", depth + 1)
            if self.peek("NONE", depth=depth + 2):
                self.take("NONE", depth=depth + 2)
                type_object["expr"] = None
            else:
                type_object["expr"] = self.parse_expression(depth + 2)
            self.take("LABEL", "ELEMENT_TYPE", depth + 1)
            type_object["element_type"] = self.parse_type(depth + 2)
            return type_object

        if kind in {"T_STRUCT", "T_UNION", "T_ENUM"}:
            label = "ENUMERATORS" if kind == "T_ENUM" else "FIELD"
            self.take("LABEL", label, depth + 1)
            type_object["field"] = self.parse_id_list(
                depth + 2, register_scope=kind == "T_ENUM"
            )
            return type_object

        raise VerificationError(f"unsupported type in AST_PRINT output: {kind}")

    def parse_statement_list(self, depth: int) -> Dict[str, Any]:
        token = self.take("NODE", depth=depth)
        name = token.value["name"]
        if name == "N_STMT_LIST_NIL":
            return self.make_node(token)
        if name != "N_STMT_LIST":
            raise VerificationError(f"expected statement list, got {name}")
        statement = self.parse_statement(depth + 1)
        remainder = self.parse_statement_list(depth + 1)
        return self.make_node(token, llink=statement, rlink=remainder)

    def parse_statement(
        self, depth: int, *, function_body: bool = False
    ) -> Dict[str, Any]:
        token = self.take("NODE", depth=depth)
        name = token.value["name"]
        if name == "N_STMT_COMPOUND":
            if not function_body:
                self.scopes.append([])
            try:
                declarations = self.parse_id_list(depth + 1, register_scope=True)
                statements = self.parse_statement_list(depth + 1)
            finally:
                if not function_body:
                    self.scopes.pop()
            return self.make_node(token, llink=declarations, rlink=statements)
        if name == "N_STMT_EMPTY" or name in {"N_STMT_CONTINUE", "N_STMT_BREAK"}:
            return self.make_node(token)
        if name == "N_STMT_EXPRESSION":
            return self.make_node(token, clink=self.parse_expression(depth + 1))
        if name == "N_STMT_RETURN":
            expression = (
                self.parse_expression(depth + 1)
                if self.peek_expression(depth + 1)
                else None
            )
            return self.make_node(token, clink=expression)
        if name == "N_STMT_IF":
            return self.make_node(
                token,
                llink=self.parse_expression(depth + 1),
                rlink=self.parse_statement(depth + 1),
            )
        if name == "N_STMT_IF_ELSE":
            return self.make_node(
                token,
                llink=self.parse_expression(depth + 1),
                clink=self.parse_statement(depth + 1),
                rlink=self.parse_statement(depth + 1),
            )
        raise VerificationError(f"unsupported statement in AST_PRINT output: {name}")

    def peek_expression(self, depth: int) -> bool:
        return (
            self.peek("NODE", depth=depth)
            and self.tokens[self.position].value["name"].startswith("N_EXP_")
        )

    def parse_expression(self, depth: int) -> Dict[str, Any]:
        token = self.take("NODE", depth=depth)
        name = token.value["name"]
        if name == "N_EXP_IDENT":
            return self.make_node(token, clink=self.parse_reference(depth + 1))
        if name in {"N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
            return self.make_node(
                token, clink=self.take("INTEGER", depth=depth + 1).value
            )
        if name in self.BINARY_EXPRESSIONS:
            return self.make_node(
                token,
                llink=self.parse_expression(depth + 1),
                rlink=self.parse_expression(depth + 1),
            )
        if name in self.UNARY_EXPRESSIONS:
            return self.make_node(token, clink=self.parse_expression(depth + 1))
        if name == "N_EXP_FUNCTION_CALL":
            return self.make_node(
                token,
                llink=self.parse_expression(depth + 1),
                rlink=self.parse_argument_list(depth + 1),
            )
        raise VerificationError(f"unsupported expression in AST_PRINT output: {name}")

    def parse_argument_list(self, depth: int) -> Dict[str, Any]:
        token = self.take("NODE", depth=depth)
        name = token.value["name"]
        if name == "N_ARG_LIST_NIL":
            return self.make_node(token)
        if name != "N_ARG_LIST":
            raise VerificationError(f"expected argument list, got {name}")
        return self.make_node(
            token,
            llink=self.parse_expression(depth + 1),
            rlink=self.parse_argument_list(depth + 1),
        )

    def parse_initializer(self, depth: int) -> Dict[str, Any]:
        token = self.take("NODE", depth=depth)
        name = token.value["name"]
        if name == "N_INIT_LIST_NIL":
            return self.make_node(token)
        if name == "N_INIT_LIST_ONE":
            return self.make_node(token, clink=self.parse_expression(depth + 1))
        if name == "N_INIT_LIST":
            return self.make_node(
                token,
                llink=self.parse_initializer(depth + 1),
                rlink=self.parse_initializer(depth + 1),
            )
        raise VerificationError(f"unsupported initializer in AST_PRINT output: {name}")


def _path(parts: Sequence[str]) -> str:
    return " > ".join(parts)


ID_FIELDS = ("name", "kind", "level", "specifier", "value", "address")


def _identity(value: Dict[str, Any]) -> Tuple[Any, ...]:
    return tuple(value.get(field) for field in ID_FIELDS)


def _node_path(value: Any, path: Sequence[str]) -> List[str]:
    if not isinstance(value, dict) or value.get("class") != "A_NODE":
        return list(path)
    name = value.get("name", "A_NODE")
    if name in {"N_EXP_IDENT", "N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
        return list(path)
    return [*path, name]


def compare(expected: Any, actual: Any) -> List[Difference]:
    """Compare two object graphs, including aliases and recursive references."""
    differences: List[Difference] = []
    expected_to_actual: Dict[int, int] = {}
    actual_to_expected: Dict[int, int] = {}

    def different(path: Sequence[str], wanted: Any, found: Any) -> None:
        differences.append(Difference(_path(path), wanted, found))

    def claim_object(wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]) -> bool:
        wanted_id = id(wanted)
        found_id = id(found)
        previous_found = expected_to_actual.get(wanted_id)
        previous_wanted = actual_to_expected.get(found_id)
        if previous_found is not None:
            if previous_found != found_id:
                different([*path, "REFERENCE_IDENTITY"], wanted, found)
            return False
        if previous_wanted is not None and previous_wanted != wanted_id:
            different([*path, "REFERENCE_IDENTITY"], wanted, found)
            return False
        expected_to_actual[wanted_id] = found_id
        actual_to_expected[found_id] = wanted_id
        return True

    def compare_value(wanted: Any, found: Any, path: Sequence[str]) -> None:
        if type(wanted) is not type(found):
            different(path, wanted, found)
            return
        if wanted is None or not isinstance(wanted, dict):
            if wanted != found:
                different(path, wanted, found)
            return

        wanted_class = wanted.get("class")
        if wanted_class != found.get("class"):
            different(path, wanted, found)
            return
        if not claim_object(wanted, found, path):
            return
        if wanted_class == "A_NODE":
            compare_node(wanted, found, path)
        elif wanted_class == "A_ID":
            compare_id(wanted, found, path)
        elif wanted_class == "A_ID_REF":
            compare_reference(wanted, found, path)
        elif wanted_class == "A_TYPE":
            compare_type(wanted, found, path)
        elif wanted != found:
            different(path, wanted, found)

    def compare_id_chain(wanted: Any, found: Any, path: Sequence[str]) -> None:
        wanted_current = wanted
        found_current = found
        occurrences: Dict[str, int] = {}

        while wanted_current is not None or found_current is not None:
            representative = wanted_current or found_current
            if not isinstance(representative, dict):
                different(path, wanted_current, found_current)
                return
            name = representative.get("name") or "<anonymous>"
            occurrences[name] = occurrences.get(name, 0) + 1
            suffix = f"[{occurrences[name]}]" if occurrences[name] > 1 else ""
            item_path = [*path, f"{name}{suffix}"]

            if wanted_current is None or found_current is None:
                different(item_path, wanted_current, found_current)
                return
            compare_value(wanted_current, found_current, item_path)
            wanted_current = wanted_current.get("link")
            found_current = found_current.get("link")

    def compare_id(wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]) -> None:
        if _identity(wanted) != _identity(found):
            different(path, wanted, found)
        compare_value(wanted.get("type"), found.get("type"), [*path, "TYPE"])
        compare_value(wanted.get("init"), found.get("init"), [*path, "INIT"])

    def compare_reference(
        wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]
    ) -> None:
        if _identity(wanted) != _identity(found):
            different(path, wanted, found)
        compare_value(wanted.get("type"), found.get("type"), [*path, "TYPE"])
        compare_value(wanted.get("target"), found.get("target"), [*path, "TARGET"])

    def compare_type(wanted: Any, found: Any, path: Sequence[str]) -> None:
        if wanted.get("kind") != found.get("kind"):
            different(path, wanted, found)
            return

        kind = wanted.get("kind")
        element_label = "RETURN_TYPE" if kind == "T_FUNC" else "ELEMENT_TYPE"
        compare_value(
            wanted.get("element_type"),
            found.get("element_type"),
            [*path, element_label],
        )
        compare_id_chain(
            wanted.get("field"),
            found.get("field"),
            [*path, "PARAMETERS" if kind == "T_FUNC" else "FIELD"],
        )
        body_path = [*path[:-1], "BODY"] if kind == "T_FUNC" else [*path, "EXPR"]
        compare_value(wanted.get("expr"), found.get("expr"), body_path)

    def statement_label(statement: Any) -> str:
        if not isinstance(statement, dict):
            return "STATEMENT"
        names = {
            "N_STMT_RETURN": "RETURN",
            "N_STMT_EXPRESSION": "EXPRESSION",
            "N_STMT_COMPOUND": "BLOCK",
            "N_STMT_IF": "IF",
            "N_STMT_IF_ELSE": "IF_ELSE",
        }
        return names.get(statement.get("name"), "STATEMENT")

    def compare_node(
        wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]
    ) -> None:
        if found.get("class") != "A_NODE" or wanted.get("name") != found.get("name"):
            different(path, wanted, found)
            return

        name = wanted.get("name")
        compare_value(wanted.get("type"), found.get("type"), [*path, "TYPE"])
        if wanted.get("value") != found.get("value"):
            different([*path, "VALUE"], wanted.get("value"), found.get("value"))

        if name == "N_PROGRAM":
            compare_value(wanted.get("llink"), found.get("llink"), [*path, "llink"])
            compare_id_chain(wanted.get("clink"), found.get("clink"), path)
            compare_value(wanted.get("rlink"), found.get("rlink"), [*path, "rlink"])
            return
        if name == "N_STMT_COMPOUND":
            compare_id_chain(
                wanted.get("llink"), found.get("llink"), [*path, "DECLARATIONS"]
            )
            compare_value(wanted.get("clink"), found.get("clink"), [*path, "clink"])
            compare_value(wanted.get("rlink"), found.get("rlink"), path)
            return
        if name == "N_EXP_IDENT":
            compare_value(wanted.get("llink"), found.get("llink"), [*path, "llink"])
            before = len(differences)
            compare_value(wanted.get("clink"), found.get("clink"), path)
            if len(differences) > before and differences[-1].path == _path(path):
                differences[-1] = Difference(_path(path), wanted, found)
            compare_value(wanted.get("rlink"), found.get("rlink"), [*path, "rlink"])
            return
        if name in {"N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
            if wanted.get("clink") != found.get("clink"):
                different(path, wanted, found)
            compare_value(wanted.get("llink"), found.get("llink"), [*path, "llink"])
            compare_value(wanted.get("rlink"), found.get("rlink"), [*path, "rlink"])
            return
        if name == "N_STMT_LIST":
            wanted_statement = wanted.get("llink")
            found_statement = found.get("llink")
            compare_value(
                wanted_statement,
                found_statement,
                [*path, statement_label(wanted_statement)],
            )
            compare_value(wanted.get("clink"), found.get("clink"), [*path, "clink"])
            compare_value(wanted.get("rlink"), found.get("rlink"), path)
            return

        for link in ("llink", "clink", "rlink"):
            wanted_child = wanted.get(link)
            found_child = found.get(link)
            child = wanted_child if wanted_child is not None else found_child
            compare_value(wanted_child, found_child, _node_path(child, path))

    compare_value(expected, actual, ("N_PROGRAM",))
    return differences


def describe(value: Any) -> str:
    if value is None:
        return "0"
    if isinstance(value, str):
        return value
    if isinstance(value, dict):
        class_name = value.get("class")
        if class_name == "A_NODE":
            name = value.get("name", "A_NODE")
            if name == "N_EXP_IDENT":
                identity = value.get("clink") or {}
                return f'N_EXP_IDENT({identity.get("name", "?")})'
            if name in {"N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
                return f"{name}({value.get('clink')})"
            return name
        if class_name == "A_TYPE":
            return value.get("kind") or "A_TYPE(unresolved)"
        if class_name in {"A_ID", "A_ID_REF"}:
            return (
                f'A_ID({value.get("name")!r}, {value.get("kind")}, '
                f'scope={value.get("level")}, spec={value.get("specifier")})'
            )
    return repr(value)


def format_tree(root: Optional[Dict[str, Any]]) -> str:
    if root is None:
        return "<unavailable>"

    lines: List[str] = []
    labels: Dict[int, int] = {}
    expanded: set[int] = set()

    def emit(value: Any, indent: int, label: Optional[str] = None) -> None:
        prefix = "  " * indent
        label_prefix = f"{label}: " if label is not None else ""
        if value is None or not isinstance(value, dict):
            lines.append(f"{prefix}{label_prefix}{describe(value)}")
            return

        object_id = id(value)
        if object_id not in labels:
            labels[object_id] = len(labels) + 1
        object_label = labels[object_id]
        if object_id in expanded:
            lines.append(
                f"{prefix}{label_prefix}<ref #{object_label} {describe(value)}>"
            )
            return
        expanded.add(object_id)

        class_name = value.get("class")
        lines.append(f"{prefix}{label_prefix}#{object_label} {describe(value)}")
        if class_name == "A_NODE":
            emit(value.get("type"), indent + 1, "type")
            lines.append(f"{'  ' * (indent + 1)}value: {value.get('value')}")
            for link in ("llink", "clink", "rlink"):
                emit(value.get(link), indent + 1, link)
        elif class_name == "A_ID":
            emit(value.get("type"), indent + 1, "type")
            emit(value.get("init"), indent + 1, "init")
            emit(value.get("link"), indent + 1, "link")
        elif class_name == "A_ID_REF":
            emit(value.get("type"), indent + 1, "type")
            emit(value.get("target"), indent + 1, "target")
        elif class_name == "A_TYPE":
            emit(value.get("element_type"), indent + 1, "element_type")
            emit(value.get("field"), indent + 1, "field")
            emit(value.get("expr"), indent + 1, "expr")

    emit(root, 0)
    return "\n".join(lines)


def run_compiler(parser: Path, source: Path) -> str:
    environment = os.environ.copy()
    for name in tuple(environment):
        if name.startswith("AST_TEST_"):
            del environment[name]
    environment["AST_PRINT"] = "1"

    completed = subprocess.run(
        [str(parser)],
        input=source.read_bytes(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=ROOT,
        env=environment,
        check=False,
    )
    stdout = completed.stdout.decode(errors="replace")
    stderr = completed.stderr.decode(errors="replace")
    if completed.returncode != 0:
        details = stderr.strip() or stdout.strip() or "no diagnostic output"
        raise VerificationError(
            f"compiler exited with status {completed.returncode}: {details}"
        )
    return stdout


def make_test_case(source: AstSource) -> TestCase:
    normalized_number = str(int(source.number))
    registered = CASES.get(normalized_number)
    expectation = None
    if registered is not None and registered[0] == source.path.name:
        expectation = registered[1]
    return TestCase(source.number, source.slug, source.path, expectation)


def discover_cases() -> List[TestCase]:
    return [make_test_case(source) for source in discover_ast_sources(ROOT)]


def verify_case(case: TestCase, parser: Path) -> CaseResult:
    if case.expectation is None:
        return CaseResult(case, "SKIP")

    expected = case.expectation()
    try:
        output = run_compiler(parser, case.source)
        actual = AstPrintParser(tokenize(output)).parse()
        differences = compare(expected, actual)
    except (OSError, VerificationError) as error:
        return CaseResult(
            case,
            "FAIL",
            expected=expected,
            differences=[Difference("COMPILER", "successful AST_PRINT output", str(error))],
        )

    return CaseResult(
        case,
        "PASS" if not differences else "FAIL",
        expected=expected,
        actual=actual,
        differences=differences,
    )


def print_difference(difference: Difference) -> None:
    print(f"Path: {difference.path}")
    print(f"Expected: {describe(difference.expected)}")
    print(f"Actual:   {describe(difference.actual)}")


def print_result(result: CaseResult, show: bool, diff_only: bool) -> None:
    case = result.case
    print(f"[{result.status}] AST {case.number} - {case.slug}")

    if result.status == "SKIP":
        print("Reason: expected AST is not implemented")
        return
    if result.status == "PASS" and not show:
        return

    if show:
        print("\nExpected AST:")
        print(format_tree(result.expected))
        print("\nActual AST:")
        print(format_tree(result.actual))

    if result.status == "FAIL":
        differences = result.differences or []
        selected = differences if diff_only or show else differences[:1]
        for index, difference in enumerate(selected):
            print()
            print_difference(difference)
            if index == 49:
                print(f"\n... {len(selected) - 50} more differences")
                break


def parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(prog="syntax", description=__doc__)
    parser.add_argument(
        "case",
        nargs="?",
        help="AST test number, for example 24",
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="run every tests/ast input (unimplemented expectations are SKIP)",
    )
    output = parser.add_mutually_exclusive_group()
    output.add_argument(
        "--show",
        action="store_true",
        help="show the normalized expected and actual ASTs",
    )
    output.add_argument(
        "--diff",
        action="store_true",
        help="show every structural difference without full ASTs",
    )
    return parser.parse_args(argv)


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = parse_args(argv)
    if args.all == (args.case is not None):
        print("error: specify one test number or --all")
        return 2

    sources = discover_ast_sources(ROOT)
    if args.all:
        selected_cases = [make_test_case(source) for source in sources]
    else:
        try:
            selected_source = choose_numbered_source(ROOT, sources, args.case)
        except CaseSelectionError as error:
            print(f"error: {error}")
            return 2
        selected_cases = [make_test_case(selected_source)]

    try:
        with build_parser() as parser:
            results = [verify_case(case, parser) for case in selected_cases]
    except (OSError, ParserBuildError, VerificationError) as error:
        print(f"[ERROR] {error}")
        return 2

    for index, result in enumerate(results):
        if index:
            print()
        print_result(result, args.show, args.diff)

    failed = [result for result in results if result.status == "FAIL"]
    if args.all:
        passed_count = sum(result.status == "PASS" for result in results)
        skipped_count = sum(result.status == "SKIP" for result in results)
        print()
        print(
            f"Summary: {passed_count} passed, {len(failed)} failed, "
            f"{skipped_count} skipped, {len(results)} total"
        )
        if failed:
            failed_numbers = ", ".join(result.case.number for result in failed)
            print(f"Failed tests: {failed_numbers}")

    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())

