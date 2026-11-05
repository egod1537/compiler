#!/usr/bin/env python3
"""Short CLI for parsing numbered tests/ast inputs with the current compiler."""

from __future__ import annotations

import argparse
from dataclasses import dataclass
import os
from pathlib import Path
import subprocess
from typing import List, Optional, Sequence

from ast_cases import (
    AstSource,
    CaseSelectionError,
    choose_numbered_source,
    discover_ast_sources,
    resolve_source_path,
)
from parser_build import ParserBuildError, build_parser


ROOT = Path(__file__).resolve().parents[1]


@dataclass
class ParseResult:
    source: AstSource
    returncode: int
    stdout: str
    stderr: str


def parser_arguments(source: AstSource) -> List[str]:
    modes = {
        "03_precedence.c": ["--ast-test", "precedence"],
        "04_parentheses.c": ["--ast-test", "parentheses"],
    }
    return modes.get(source.path.name, [])


def parser_environment(print_ast: bool) -> dict:
    environment = os.environ.copy()
    for name in tuple(environment):
        if name.startswith("AST_TEST_"):
            del environment[name]
    if print_ast:
        environment["AST_PRINT"] = "1"
    else:
        environment.pop("AST_PRINT", None)
    return environment


def run_executable(parser: Path, source: AstSource, print_ast: bool) -> ParseResult:
    completed = subprocess.run(
        [str(parser), *parser_arguments(source)],
        input=source.path.read_bytes(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=ROOT,
        env=parser_environment(print_ast),
        check=False,
    )
    return ParseResult(
        source,
        completed.returncode,
        completed.stdout.decode(errors="replace"),
        completed.stderr.decode(errors="replace"),
    )


def run_parser_cmd(source: AstSource, print_ast: bool) -> ParseResult:
    command = ["cmd.exe", "/d", "/c", str(ROOT / "parser.cmd"), str(source.path)]
    completed = subprocess.run(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        cwd=ROOT,
        env=parser_environment(print_ast),
        check=False,
    )
    return ParseResult(
        source,
        completed.returncode,
        completed.stdout.decode(errors="replace"),
        completed.stderr.decode(errors="replace"),
    )


def print_result(result: ParseResult) -> None:
    if result.stdout:
        print(result.stdout, end="" if result.stdout.endswith("\n") else "\n")
    if result.stderr:
        print(result.stderr, end="" if result.stderr.endswith("\n") else "\n")
    status = "PASS" if result.returncode == 0 else "FAIL"
    print(f"[{status}] PARSE AST {result.source.number} - {result.source.slug}")


def parse_args(argv: Optional[Sequence[str]] = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(prog="parse", description=__doc__)
    parser.add_argument("input", nargs="?", help="AST number or C source path")
    parser.add_argument("--all", action="store_true", help="parse every tests/ast input")
    parser.add_argument(
        "--print",
        dest="print_ast",
        action="store_true",
        help="set AST_PRINT=1 and show print.c output",
    )
    return parser.parse_args(argv)


def select_sources(args: argparse.Namespace) -> List[AstSource]:
    discovered = discover_ast_sources(ROOT)
    if args.all:
        if args.input is not None:
            raise CaseSelectionError("do not combine an input with --all")
        return discovered
    if args.input is None:
        raise CaseSelectionError("specify an AST test number, C source path, or --all")
    if args.input.isdigit():
        return [choose_numbered_source(ROOT, discovered, args.input)]
    return [resolve_source_path(ROOT, args.input)]


def run_on_windows(sources: Sequence[AstSource], print_ast: bool) -> List[ParseResult]:
    first = run_parser_cmd(sources[0], print_ast)
    results = [first]
    if len(sources) == 1:
        return results

    parser = ROOT / "parser.exe"
    if first.returncode != 0 or not parser.is_file():
        details = first.stderr.strip() or first.stdout.strip() or "no diagnostic output"
        raise ParserBuildError(
            "parser.cmd could not build and run the first test; --all was stopped: "
            + details
        )
    results.extend(run_executable(parser, source, print_ast) for source in sources[1:])
    return results


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = parse_args(argv)
    try:
        sources = select_sources(args)
        if os.name == "nt":
            results = run_on_windows(sources, args.print_ast)
        else:
            with build_parser() as parser:
                results = [
                    run_executable(parser, source, args.print_ast) for source in sources
                ]
    except (OSError, CaseSelectionError, ParserBuildError) as error:
        print(f"[ERROR] {error}")
        return 1

    for index, result in enumerate(results):
        if index:
            print()
        print_result(result)

    failed = [result for result in results if result.returncode != 0]
    if args.all:
        print()
        print(
            f"Summary: {len(results) - len(failed)} passed, "
            f"{len(failed)} failed, {len(results)} total"
        )
        if failed:
            print("Failed tests: " + ", ".join(result.source.number for result in failed))
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())

