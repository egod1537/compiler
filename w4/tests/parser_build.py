"""Build the current compiler sources in an isolated temporary directory."""

from __future__ import annotations

import contextlib
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
from typing import Iterator, Sequence


ROOT = Path(__file__).resolve().parents[1]


class ParserBuildError(Exception):
    pass


def _run_build(command: Sequence[str]) -> None:
    completed = subprocess.run(
        command,
        cwd=ROOT,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        raise ParserBuildError(
            f"build command failed ({' '.join(command)}):\n{completed.stdout.rstrip()}"
        )


@contextlib.contextmanager
def build_parser() -> Iterator[Path]:
    required = ("bison", "flex", "gcc")
    missing = [program for program in required if shutil.which(program) is None]
    if missing:
        raise ParserBuildError(f"missing build tools: {', '.join(missing)}")

    with tempfile.TemporaryDirectory(prefix="w4-ast-") as directory:
        temp = Path(directory)
        generated_parser = temp / "y.tab.c"
        generated_header = temp / "y.tab.h"
        generated_lexer = temp / "lex.yy.c"
        executable = temp / ("parser.exe" if os.name == "nt" else "parser")

        _run_build(
            [
                "bison",
                "-y",
                "-d",
                f"--defines={generated_header}",
                "-o",
                str(generated_parser),
                str(ROOT / "c.y"),
            ]
        )
        _run_build(["flex", "-o", str(generated_lexer), str(ROOT / "c.l")])
        _run_build(
            [
                "gcc",
                "-Wall",
                "-Wextra",
                "-std=c11",
                "-g",
                "-O0",
                "-I",
                str(temp),
                "-I",
                str(ROOT),
                str(generated_parser),
                str(generated_lexer),
                str(ROOT / "semantic.c"),
                str(ROOT / "syntax_tree.c"),
                str(ROOT / "logger.c"),
                str(ROOT / "print.c"),
                str(ROOT / "tests" / "ast_assert.c"),
                str(ROOT / "parser_main.c"),
                "-o",
                str(executable),
            ]
        )
        yield executable

