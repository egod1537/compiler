# Parser tests

Semantic test cases, code, and runners live together under `sem/`. Run them
from the project root on Unix-like systems:

```sh
make test-sem
```

Chapter 5 declaration-error integration cases live under `semerr/` and feed
real C input to the active Lex/Yacc parser:

```sh
make test-semerr
make test-semerr TEST=1
make test-semerr TEST=list
```

On Windows:

```powershell
.\tests\sem\run.cmd
```

AST/parser cases, assertion code, expected graphs, and runners live under
`ast/`. Run a manual AST comparison with the current parser sources:

```powershell
.\tests\ast\check.cmd 24
.\tests\ast\check.cmd 24 --diff
.\tests\ast\check.cmd --all
```

`ast/valid/` contains inputs that must parse successfully. `ast/invalid/`
contains inputs that must produce a syntax error.
`ast/unsupported/` contains extended-language inputs outside the parser's
current textbook scope; they are kept as future implementation cases and are
not counted as successful-parser tests.

On Unix-like systems, install a C11 compiler, Bison, Flex, and Make. Then build
the parser from the project root:

```sh
make
```

The Makefile enables the POSIX interfaces required by the scanner and logger,
so the same command works on macOS and Linux. Run only the AST/parser tests
with:

```sh
make test-ast
```

Run both the parser and semantic test suites with:

```sh
make test
```

All suites use the same optional numbered-test interface. Use `TEST=list` to
show the stable numbers, `TEST=N` to run one test, or omit `TEST` to run all:

```sh
make test-sem TEST=list
make test-sem TEST=4
make test-ast TEST=4
make test-ast-exp TEST=4
make test-astexp TEST=4
make test-semerr TEST=4
```

Selectable C test functions follow one naming rule: `GROUP_NN_Name`.

- `GROUP` is an uppercase group code: `SEM` for legacy semantic unit tests,
  `SEMERR` for Chapter 5 parser error integration tests, `AST` for parser
  acceptance tests, or `ASTEXP` for selectable expected-AST tests.
- `NN` is the suite-local two-digit number used by `TEST=N`.
- `Name` is a PascalCase description.
- Examples: `SEM_04_Scope`, `ASTEXP_03_For`.

Shared assertion helpers and test dispatch functions are not independently
selectable tests, so they do not receive a test number.

The runners use colored output when connected to a terminal. Set
`NO_COLOR=1` to disable colors or `FORCE_COLOR=1` to force ANSI colors when
output is redirected.

Run one input directly when debugging:

```sh
./parser < tests/ast/valid/03_control_flow.c
./parser < tests/ast/invalid/02_incomplete_expression.c
```

Remove generated files and build outputs with:

```sh
make clean
```
