# Chapter 5 syntax analyzer

This directory contains the assignment implementation based on the professor's
baseline in `../w4-1`.

## Assignment scope

- Parses the Chapter 5 subset and prints its syntax tree.
- Supports both LF and CRLF input.
- Uses a pointer-sized `YYSTYPE` (`long` on the target Unix environment and
  `long long` on 64-bit Windows).
- Excludes initializers and storage-class specifiers from the grammar.
- Matches `../w4-1` for accepted/rejected input and syntax-tree output,
  including rejection of `main(void)` and the absence of a `double` type.
- Keeps the original `semantic.c`, `syntax_tree.c`, and `logger.c` structure
  and the existing Korean section comments.
- Reports stable error tags for lexical, syntax, Chapter 5 declaration, and
  internal errors while preserving the lecture's declaration error numbers.

`initialize()` in `semantic.c` initializes the parser's built-in type and
predefined-identifier tables. It is unrelated to C declaration initializers
such as `int x = 1`.

The production parser and AST test harness are linked separately. Test-only
AST assertion sources are not part of the production `parser` executable.

## Build and run

Unix/MSYS2:

```sh
make
./parser < tests/ch5/valid/01_function.c
make test
```

The grammar also builds with the Bison 2.3 shipped by macOS. `YYSTYPE` is
declared in `parse_value.h`, so generated parser and scanner sources use the
same pointer-sized value type without relying on newer Bison directives.

Run one suite or one numbered test:

```sh
make test-ast
make test-astexp TEST=1
make test-sem TEST=1
make test-semerr
make test-semerr TEST=1
make test-semerr TEST=list
make test-baseline
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
- `SEM`: unit tests for the active `semantic.c` helper API.
- `SEMERR`: real C input integration tests for Chapter 5 declaration errors,
  false-positive prevention, and stable error classification.
- `BASELINE`: builds `../w4-1` and compares both parsers' exit status on 125 C inputs.
  Successful inputs must also produce the same syntax tree after pointer
  addresses are normalized; error output is compared as well.

Tagged diagnostics used by SEMERR are enabled with `COMPILER_ERROR_TAGS=1`:

```text
[DECLARATION_ERROR:12] line 3: redeclaration of identifier 'a'
[SYNTAX_ERROR] line 5: syntax error near 'return'
```

SEMERR compares the bracketed classification and lecture error code, not the
complete descriptive text. Chapter 7 expression/type semantic analysis is out
of scope.

Without that environment variable, diagnostics use the same format as
`w4-1`. The opt-in prefixes let tests distinguish lexical, grammar,
declaration, and internal errors without changing normal compiler behavior.
