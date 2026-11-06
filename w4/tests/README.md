# Parser tests

Semantic test cases, code, and runners live together under `sem/`. Run them
from the project root on Unix-like systems:

```sh
make test-sem
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

The runner uses colored output when connected to a terminal. Set `NO_COLOR=1`
to disable colors.

Run one input directly when debugging:

```sh
./parser < tests/ast/valid/03_control_flow.c
./parser < tests/ast/invalid/02_incomplete_expression.c
```

Remove generated files and build outputs with:

```sh
make clean
```
