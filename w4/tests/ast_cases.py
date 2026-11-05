"""Shared discovery and selection for numbered tests/ast source files."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import re
import sys
from typing import Callable, List, Sequence


CASE_NAME_RE = re.compile(r"^(\d+)_([^/\\]+)\.c$")


class CaseSelectionError(Exception):
    pass


@dataclass(frozen=True)
class AstSource:
    number: str
    slug: str
    path: Path


def source_from_path(path: Path) -> AstSource:
    match = CASE_NAME_RE.match(path.name)
    if match is None:
        return AstSource("file", path.stem, path)
    return AstSource(match.group(1), match.group(2), path)


def discover_ast_sources(root: Path) -> List[AstSource]:
    ast_directory = root / "tests" / "ast"
    sources = [source_from_path(path) for path in ast_directory.glob("[0-9]*_*.c")]
    return sorted(
        sources,
        key=lambda source: (
            int(source.number) if source.number.isdigit() else sys.maxsize,
            source.path.name,
        ),
    )


def find_numbered_sources(sources: Sequence[AstSource], number: str) -> List[AstSource]:
    if not number.isdigit():
        raise CaseSelectionError(f"invalid AST test number: {number}")
    wanted = int(number)
    matches = [source for source in sources if int(source.number) == wanted]
    if not matches:
        raise CaseSelectionError(f"AST test {number} was not found")
    return matches


def choose_numbered_source(
    root: Path,
    sources: Sequence[AstSource],
    number: str,
    input_fn: Callable[[str], str] = input,
) -> AstSource:
    matches = find_numbered_sources(sources, number)
    if len(matches) == 1:
        return matches[0]

    print(f"Multiple AST tests match {number}:")
    for index, source in enumerate(matches, start=1):
        print(f"  {index}) {source.path.relative_to(root)}")

    while True:
        try:
            answer = input_fn(f"Select [1-{len(matches)}]: ").strip()
        except EOFError as error:
            raise CaseSelectionError(
                "selection input ended; pass one of the displayed file paths directly"
            ) from error
        if answer.isdigit() and 1 <= int(answer) <= len(matches):
            return matches[int(answer) - 1]
        print(f"Enter a number from 1 to {len(matches)}.")


def resolve_source_path(root: Path, argument: str) -> AstSource:
    candidate = Path(argument).expanduser()
    if not candidate.is_absolute():
        candidate = root / candidate
    candidate = candidate.resolve()
    if not candidate.is_file():
        raise CaseSelectionError(f"input file was not found: {argument}")
    return source_from_path(candidate)

