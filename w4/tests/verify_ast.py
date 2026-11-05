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


NODE_RE = re.compile(r"^(N_[A-Z0-9_]+)\s+\(.+,-?\d+\)$")
ID_RE = re.compile(
    r'^\(ID="([^"]*)"\).*\bKIND:([A-Z_]+).*\bLEV=(-?\d+)\b'
)
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


def _content(line: str) -> str:
    text = line.strip()
    while text.startswith("|"):
        text = text[1:].lstrip()
    return text


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
        content = _content(raw_line)
        if not content:
            continue

        node_match = NODE_RE.match(content)
        if node_match:
            tokens.append(Token("NODE", node_match.group(1), line_number))
            continue

        id_match = ID_RE.match(content)
        if id_match:
            tokens.append(
                Token(
                    "ID",
                    {
                        "name": id_match.group(1),
                        "kind": "ID_" + id_match.group(2),
                        "level": int(id_match.group(3)),
                    },
                    line_number,
                )
            )
            continue

        if content in LABELS:
            tokens.append(Token("LABEL", content, line_number))
            continue

        if content == "(int)":
            tokens.append(Token("TYPE_KIND", "T_INT", line_number))
            continue
        if content == "(float)":
            tokens.append(Token("TYPE_KIND", "T_FLOAT", line_number))
            continue
        if content.startswith("(char ") and content.endswith(")"):
            tokens.append(Token("TYPE_KIND", "T_CHAR", line_number))
            continue
        if content == "(void)":
            tokens.append(Token("TYPE_KIND", "T_VOID", line_number))
            continue
        if content == "(null)":
            tokens.append(Token("TYPE_KIND", "T_NULL", line_number))
            continue
        if content.startswith("(DONE:"):
            raise VerificationError(
                "print.c elided a repeated type as DONE; this verifier cannot infer its structure"
            )
        if content in TYPE_WORDS:
            tokens.append(Token("TYPE_KIND", TYPE_WORDS[content], line_number))
            continue
        if content == "(none)":
            tokens.append(Token("NONE", None, line_number))
            continue
        if INTEGER_RE.match(content):
            tokens.append(Token("INTEGER", int(content), line_number))
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

    def peek(self, kind: Optional[str] = None, value: Any = None) -> bool:
        if self.position >= len(self.tokens):
            return False
        token = self.tokens[self.position]
        return (kind is None or token.kind == kind) and (value is None or token.value == value)

    def take(self, kind: str, value: Any = None) -> Token:
        if self.position >= len(self.tokens):
            raise VerificationError(f"unexpected end of AST_PRINT output; expected {value or kind}")
        token = self.tokens[self.position]
        if token.kind != kind or (value is not None and token.value != value):
            raise VerificationError(
                f"tree line {token.line}: expected {value or kind}, got {token.value!r}"
            )
        self.position += 1
        return token

    @staticmethod
    def make_node(name: str, llink: Any = None, clink: Any = None, rlink: Any = None) -> Dict[str, Any]:
        return {
            "class": "A_NODE",
            "name": name,
            "llink": llink,
            "clink": clink,
            "rlink": rlink,
        }

    @staticmethod
    def make_type(
        kind: str,
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
        self.take("NODE", "N_PROGRAM")
        program = self.make_node("N_PROGRAM", clink=self.parse_id_list())
        if self.position != len(self.tokens):
            token = self.tokens[self.position]
            raise VerificationError(
                f"tree line {token.line}: unexpected trailing value {token.value!r}"
            )
        return program

    def parse_id_list(self) -> Optional[Dict[str, Any]]:
        items: List[Dict[str, Any]] = []
        while self.peek("ID"):
            items.append(self.parse_declaration())

        head: Optional[Dict[str, Any]] = None
        for item in reversed(items):
            item["link"] = head
            head = item
        return head

    def parse_declaration(self) -> Dict[str, Any]:
        identity = self.take("ID").value
        self.take("LABEL", "TYPE")
        declared_type = self.parse_type()
        return {
            "class": "A_ID",
            **identity,
            "type": declared_type,
            "link": None,
        }

    def parse_reference(self) -> Dict[str, Any]:
        identity = self.take("ID").value
        return {"class": "A_ID_REF", **identity}

    def parse_type(self) -> Dict[str, Any]:
        kind = self.take("TYPE_KIND").value
        if kind in {"T_INT", "T_FLOAT", "T_CHAR", "T_VOID", "T_NULL"}:
            return self.make_type(kind)

        if kind == "T_FUNC":
            self.take("LABEL", "PARAMETER")
            parameters = self.parse_id_list()
            self.take("LABEL", "TYPE")
            return_type = self.parse_type()
            body = None
            if self.peek("LABEL", "BODY"):
                self.take("LABEL", "BODY")
                body = self.parse_statement()
            return self.make_type(kind, return_type, parameters, body)

        if kind == "T_POINTER":
            self.take("LABEL", "ELEMENT_TYPE")
            return self.make_type(kind, element_type=self.parse_type())

        if kind == "T_ARRAY":
            self.take("LABEL", "INDEX")
            if self.peek("NONE"):
                self.take("NONE")
                size = None
            else:
                size = self.parse_expression()
            self.take("LABEL", "ELEMENT_TYPE")
            return self.make_type(kind, self.parse_type(), expr=size)

        if kind in {"T_STRUCT", "T_UNION", "T_ENUM"}:
            label = "ENUMERATORS" if kind == "T_ENUM" else "FIELD"
            self.take("LABEL", label)
            return self.make_type(kind, field=self.parse_id_list())

        raise VerificationError(f"unsupported type in AST_PRINT output: {kind}")

    def parse_statement_list(self) -> Dict[str, Any]:
        name = self.take("NODE").value
        if name == "N_STMT_LIST_NIL":
            return self.make_node(name)
        if name != "N_STMT_LIST":
            raise VerificationError(f"expected statement list, got {name}")
        statement = self.parse_statement()
        remainder = self.parse_statement_list()
        return self.make_node(name, llink=statement, rlink=remainder)

    def parse_statement(self) -> Dict[str, Any]:
        name = self.take("NODE").value
        if name == "N_STMT_COMPOUND":
            declarations = self.parse_id_list()
            statements = self.parse_statement_list()
            return self.make_node(name, llink=declarations, rlink=statements)
        if name == "N_STMT_EMPTY" or name in {"N_STMT_CONTINUE", "N_STMT_BREAK"}:
            return self.make_node(name)
        if name == "N_STMT_EXPRESSION":
            return self.make_node(name, clink=self.parse_expression())
        if name == "N_STMT_RETURN":
            expression = self.parse_expression() if self.peek_expression() else None
            return self.make_node(name, clink=expression)
        if name == "N_STMT_IF":
            return self.make_node(
                name, llink=self.parse_expression(), rlink=self.parse_statement()
            )
        if name == "N_STMT_IF_ELSE":
            return self.make_node(
                name,
                llink=self.parse_expression(),
                clink=self.parse_statement(),
                rlink=self.parse_statement(),
            )
        raise VerificationError(f"unsupported statement in AST_PRINT output: {name}")

    def peek_expression(self) -> bool:
        return self.peek("NODE") and self.tokens[self.position].value.startswith("N_EXP_")

    def parse_expression(self) -> Dict[str, Any]:
        name = self.take("NODE").value
        if name == "N_EXP_IDENT":
            return self.make_node(name, clink=self.parse_reference())
        if name in {"N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
            return self.make_node(name, clink=self.take("INTEGER").value)
        if name in self.BINARY_EXPRESSIONS:
            return self.make_node(
                name, llink=self.parse_expression(), rlink=self.parse_expression()
            )
        if name in self.UNARY_EXPRESSIONS:
            return self.make_node(name, clink=self.parse_expression())
        if name == "N_EXP_FUNCTION_CALL":
            return self.make_node(
                name, llink=self.parse_expression(), rlink=self.parse_argument_list()
            )
        raise VerificationError(f"unsupported expression in AST_PRINT output: {name}")

    def parse_argument_list(self) -> Dict[str, Any]:
        name = self.take("NODE").value
        if name == "N_ARG_LIST_NIL":
            return self.make_node(name)
        if name != "N_ARG_LIST":
            raise VerificationError(f"expected argument list, got {name}")
        return self.make_node(
            name,
            llink=self.parse_expression(),
            rlink=self.parse_argument_list(),
        )


def _path(parts: Sequence[str]) -> str:
    return " > ".join(parts)


def _identity(value: Dict[str, Any]) -> Tuple[Any, Any, Any]:
    return value.get("name"), value.get("kind"), value.get("level")


def _node_path(value: Any, path: Sequence[str]) -> List[str]:
    if not isinstance(value, dict) or value.get("class") != "A_NODE":
        return list(path)
    name = value.get("name", "A_NODE")
    if name in {"N_EXP_IDENT", "N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
        return list(path)
    return [*path, name]


def compare(expected: Any, actual: Any) -> List[Difference]:
    """Compare normalized structures while producing source-oriented paths."""
    differences: List[Difference] = []

    def different(path: Sequence[str], wanted: Any, found: Any) -> None:
        differences.append(Difference(_path(path), wanted, found))

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
        elif wanted_class == "A_NODE":
            compare_node(wanted, found, path)
        elif wanted_class == "A_ID":
            compare_id(wanted, found, path)
        elif wanted_class == "A_ID_REF":
            if _identity(wanted) != _identity(found):
                different(path, wanted, found)
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
            compare_id(wanted_current, found_current, item_path)
            wanted_current = wanted_current.get("link")
            found_current = found_current.get("link")

    def compare_id(wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]) -> None:
        if found.get("class") != "A_ID":
            different(path, wanted, found)
            return
        if _identity(wanted) != _identity(found):
            different(path, wanted, found)
        compare_type(wanted.get("type"), found.get("type"), [*path, "TYPE"])

    def compare_type(wanted: Any, found: Any, path: Sequence[str]) -> None:
        if not isinstance(wanted, dict) or not isinstance(found, dict):
            compare_value(wanted, found, path)
            return
        if wanted.get("class") != "A_TYPE" or found.get("class") != "A_TYPE":
            different(path, wanted, found)
            return
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

    def compare_statement_chain(wanted: Any, found: Any, path: Sequence[str]) -> None:
        index = 1
        while True:
            if not isinstance(wanted, dict) or not isinstance(found, dict):
                compare_value(wanted, found, [*path, f"STATEMENT[{index}]"])
                return
            wanted_name = wanted.get("name")
            found_name = found.get("name")
            if wanted_name == "N_STMT_LIST_NIL" or found_name == "N_STMT_LIST_NIL":
                if wanted_name != found_name:
                    different([*path, f"STATEMENT[{index}]"], wanted, found)
                return
            if wanted_name != "N_STMT_LIST" or found_name != "N_STMT_LIST":
                different([*path, f"STATEMENT[{index}]"], wanted, found)
                return

            wanted_statement = wanted.get("llink")
            found_statement = found.get("llink")
            label = statement_label(wanted_statement, index)
            compare_value(wanted_statement, found_statement, [*path, label])
            wanted = wanted.get("rlink")
            found = found.get("rlink")
            index += 1

    def statement_label(statement: Any, index: int) -> str:
        if not isinstance(statement, dict):
            return f"STATEMENT[{index}]"
        names = {
            "N_STMT_RETURN": "RETURN",
            "N_STMT_EXPRESSION": "EXPRESSION",
            "N_STMT_COMPOUND": "BLOCK",
            "N_STMT_IF": "IF",
            "N_STMT_IF_ELSE": "IF_ELSE",
        }
        return names.get(statement.get("name"), f"STATEMENT[{index}]")

    def compare_node(
        wanted: Dict[str, Any], found: Dict[str, Any], path: Sequence[str]
    ) -> None:
        if found.get("class") != "A_NODE" or wanted.get("name") != found.get("name"):
            different(path, wanted, found)
            return

        name = wanted.get("name")
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
            compare_statement_chain(wanted.get("rlink"), found.get("rlink"), path)
            return
        if name == "N_EXP_IDENT":
            if _identity(wanted.get("clink", {})) != _identity(found.get("clink", {})):
                different(path, wanted, found)
            compare_value(wanted.get("llink"), found.get("llink"), [*path, "llink"])
            compare_value(wanted.get("rlink"), found.get("rlink"), [*path, "rlink"])
            return
        if name in {"N_EXP_INT_CONST", "N_EXP_CHAR_CONST"}:
            if wanted.get("clink") != found.get("clink"):
                different(path, wanted, found)
            compare_value(wanted.get("llink"), found.get("llink"), [*path, "llink"])
            compare_value(wanted.get("rlink"), found.get("rlink"), [*path, "rlink"])
            return
        if name in {"N_STMT_LIST", "N_STMT_LIST_NIL"}:
            compare_statement_chain(wanted, found, path)
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
            return value.get("kind", "A_TYPE")
        if class_name in {"A_ID", "A_ID_REF"}:
            return (
                f'A_ID({value.get("name")!r}, {value.get("kind")}, '
                f'scope={value.get("level")})'
            )
    return repr(value)


def format_tree(root: Optional[Dict[str, Any]]) -> str:
    if root is None:
        return "<unavailable>"

    lines: List[str] = []

    def emit(value: Any, indent: int, label: Optional[str] = None) -> None:
        prefix = "  " * indent
        label_prefix = f"{label}: " if label is not None else ""
        if value is None or not isinstance(value, dict):
            lines.append(f"{prefix}{label_prefix}{describe(value)}")
            return

        class_name = value.get("class")
        lines.append(f"{prefix}{label_prefix}{describe(value)}")
        if class_name == "A_NODE":
            for link in ("llink", "clink", "rlink"):
                emit(value.get(link), indent + 1, link)
        elif class_name == "A_ID":
            emit(value.get("type"), indent + 1, "type")
            emit(value.get("link"), indent + 1, "link")
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

