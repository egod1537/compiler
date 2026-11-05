# Parser tests

Run the semantic unit tests from the project root:

```powershell
.\tests\run-unit.cmd
```

Run a manual AST comparison with the current parser sources:

```powershell
.\tests\check-ast.cmd 24
.\tests\check-ast.cmd 24 --diff
.\tests\check-ast.cmd --all
```

`valid/` contains inputs that must parse successfully. `invalid/` contains
inputs that must produce a syntax error.

Build the parser and run every test from the project root:

```sh
yacc -d c.y
lex c.l
cc -o parser y.tab.c lex.yy.c -ll
./tests/run.sh ./parser
```

The runner uses colored output when connected to a terminal. Set `NO_COLOR=1`
to disable colors.

Run one input directly when debugging:

```sh
./parser < tests/valid/03_control_flow.c
./parser < tests/invalid/02_incomplete_expression.c
```
