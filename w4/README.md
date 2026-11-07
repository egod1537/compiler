# Chapter 5 syntax analyzer

This directory contains the assignment implementation based on the professor's
baseline in `../w4-1`.

## Assignment scope

- Parses the Chapter 5 subset and prints its syntax tree.
- Supports both LF and CRLF input.
- Uses a pointer-sized `YYSTYPE` (`long` on the target Unix environment and
  `long long` on 64-bit Windows).
- Excludes initializers and storage-class specifiers from the grammar.
- Excludes the previous GPT-added semantic-analysis, logging, and alternate AST
  implementation from the build.
- Reports stable error tags for lexical, syntax, Chapter 5 declaration, and
  internal errors while preserving the lecture's declaration error numbers.

`initialize()` in `support.c` is intentionally retained. It initializes the
parser's built-in type and predefined-identifier tables; it is unrelated to C
declaration initializers such as `int x = 1`.

## Build and run

Unix/MSYS2:

```sh
make
./parser < tests/ch5/valid/01_function.c
make test
```

Run one suite or one numbered test:

```sh
make test-ast
make test-astexp TEST=1
make test-sem TEST=1
make test-semerr
make test-semerr TEST=1
make test-semerr TEST=list
```

`test-ast-exp` remains as an alias for `test-astexp`.

Windows command prompt (with Bison, Flex, and GCC on `PATH`):

```bat
parser.cmd
parser.exe < tests\ch5\valid\01_function.c
powershell -ExecutionPolicy Bypass -File tests\ch5\run.ps1
```

## Test groups

- `CH5`: assignment grammar acceptance/rejection and LF/CRLF handling.
- `AST`: valid and invalid parser inputs.
- `ASTEXP`: selected expected AST cases. The PowerShell JSON graph checker is
  also available through `tests\ast\check.cmd`.
- `SEM`: preserved unit tests for the earlier GPT helper API. This suite uses
  `submission` as a test fixture and is not linked into the active parser.
- `SEMERR`: real C input integration tests for Chapter 5 declaration errors,
  false-positive prevention, and stable error classification.

Typical diagnostics are:

```text
[DECLARATION_ERROR:12] line 3: redeclaration of identifier 'a'
[SYNTAX_ERROR] line 5: syntax error near 'return'
```

SEMERR compares the bracketed classification and lecture error code, not the
complete descriptive text. Chapter 7 expression/type semantic analysis is out
of scope.
