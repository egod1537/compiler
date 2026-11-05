"""Hand-written AST expectations for the first four AST conformance cases.

These values describe the source programs in tests/ast directly.  They are not
snapshots of print.c output.  The small constructors keep the professor's
llink/clink/rlink, element_type/field/expr, and A_ID link relationships visible.
"""

from __future__ import annotations

from typing import Any, Dict, Iterable, Optional


AstValue = Any


def node(
    name: str,
    llink: AstValue = None,
    clink: AstValue = None,
    rlink: AstValue = None,
) -> Dict[str, AstValue]:
    return {
        "class": "A_NODE",
        "name": name,
        "llink": llink,
        "clink": clink,
        "rlink": rlink,
    }


def type_(
    kind: str,
    *,
    element_type: AstValue = None,
    field: AstValue = None,
    expr: AstValue = None,
) -> Dict[str, AstValue]:
    return {
        "class": "A_TYPE",
        "kind": kind,
        "element_type": element_type,
        "field": field,
        "expr": expr,
    }


def declaration(
    name: str,
    kind: str,
    level: int,
    declared_type: Dict[str, AstValue],
) -> Dict[str, AstValue]:
    return {
        "class": "A_ID",
        "name": name,
        "kind": kind,
        "level": level,
        "type": declared_type,
        "link": None,
    }


def reference(name: str, kind: str, level: int) -> Dict[str, AstValue]:
    return {
        "class": "A_ID_REF",
        "name": name,
        "kind": kind,
        "level": level,
    }


def id_list(*items: Dict[str, AstValue]) -> Optional[Dict[str, AstValue]]:
    """Connect A_ID values in source declaration order."""
    head: Optional[Dict[str, AstValue]] = None
    for item in reversed(items):
        item["link"] = head
        head = item
    return head


def int_type() -> Dict[str, AstValue]:
    return type_("T_INT")


def void_type() -> Dict[str, AstValue]:
    return type_("T_VOID")


def int_parameter(name: str) -> Dict[str, AstValue]:
    return declaration(name, "ID_PARM", 1, int_type())


def void_parameter() -> Dict[str, AstValue]:
    # In `f(void)`, `void` is an unnamed parameter declaration.
    return declaration("", "ID_PARM", 1, void_type())


def function_type(
    parameters: Iterable[Dict[str, AstValue]],
    body: AstValue = None,
) -> Dict[str, AstValue]:
    return type_(
        "T_FUNC",
        element_type=int_type(),
        field=id_list(*parameters),
        expr=body,
    )


def integer(value: int) -> Dict[str, AstValue]:
    return node("N_EXP_INT_CONST", clink=value)


def identifier(name: str, kind: str, level: int) -> Dict[str, AstValue]:
    return node("N_EXP_IDENT", clink=reference(name, kind, level))


def statement_list(*statements: Dict[str, AstValue]) -> Dict[str, AstValue]:
    result = node("N_STMT_LIST_NIL")
    for statement in reversed(statements):
        result = node("N_STMT_LIST", llink=statement, rlink=result)
    return result


def compound(
    declarations: Optional[Dict[str, AstValue]],
    *statements: Dict[str, AstValue],
) -> Dict[str, AstValue]:
    return node(
        "N_STMT_COMPOUND",
        llink=declarations,
        rlink=statement_list(*statements),
    )


def return_(expression: AstValue) -> Dict[str, AstValue]:
    return node("N_STMT_RETURN", clink=expression)


def assignment(name: str, level: int, value: int) -> Dict[str, AstValue]:
    expression = node(
        "N_EXP_ASSIGN",
        llink=identifier(name, "ID_VAR", level),
        rlink=integer(value),
    )
    return node("N_STMT_EXPRESSION", clink=expression)


def case_24() -> Dict[str, AstValue]:
    add_declaration = declaration(
        "add",
        "ID_FUNC",
        0,
        function_type((int_parameter("a"), int_parameter("b"))),
    )

    main_body = compound(None, return_(integer(0)))
    main_definition = declaration(
        "main", "ID_FUNC", 0, function_type((void_parameter(),), main_body)
    )

    add_expression = node(
        "N_EXP_ADD",
        llink=identifier("a", "ID_PARM", 1),
        rlink=identifier("b", "ID_PARM", 1),
    )
    add_body = compound(None, return_(add_expression))
    add_definition = declaration(
        "add",
        "ID_FUNC",
        0,
        function_type((int_parameter("a"), int_parameter("b")), add_body),
    )

    return node(
        "N_PROGRAM",
        clink=id_list(add_declaration, main_definition, add_definition),
    )


def case_25() -> Dict[str, AstValue]:
    add_expression = node(
        "N_EXP_ADD",
        llink=identifier("a", "ID_PARM", 1),
        rlink=identifier("b", "ID_PARM", 1),
    )
    add_body = compound(None, return_(add_expression))
    add = declaration(
        "add",
        "ID_FUNC",
        0,
        function_type((int_parameter("a"), int_parameter("b")), add_body),
    )
    return node("N_PROGRAM", clink=id_list(add))


def case_44() -> Dict[str, AstValue]:
    global_x = declaration("x", "ID_VAR", 0, int_type())

    outer_x = declaration("x", "ID_VAR", 1, int_type())
    inner_x = declaration("x", "ID_VAR", 2, int_type())
    inner_block = compound(id_list(inner_x), assignment("x", 2, 2))
    main_body = compound(
        id_list(outer_x),
        assignment("x", 1, 1),
        inner_block,
        return_(identifier("x", "ID_VAR", 1)),
    )
    main = declaration(
        "main", "ID_FUNC", 0, function_type((void_parameter(),), main_body)
    )

    return node("N_PROGRAM", clink=id_list(global_x, main))


def case_59() -> Dict[str, AstValue]:
    function = declaration("f", "ID_FUNC", 0, function_type(()))
    return node("N_PROGRAM", clink=id_list(function))


CASES = {
    "24": ("24_function_prototype.c", case_24),
    "25": ("25_function_parameters.c", case_25),
    "44": ("44_scope_shadowing.c", case_44),
    "59": ("59_function_declarator.c", case_59),
}

