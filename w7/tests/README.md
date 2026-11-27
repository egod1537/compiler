# w4-1 parser tests

This directory tests the appendix-based parser without changing the parser,
grammar, `type.h`, or `print.c`. The suite contains exactly 65 cases:

| Category | IDs | Count | What is checked |
|---|---|---:|---|
| Normal parsing | `P01`-`P20` | 20 | declarations, functions, aggregates, arrays, pointers, and control flow |
| AST | `A01`-`A15` | 15 | node kinds, tree depth, child order, precedence, calls, and statements |
| Errors | `E01`-`E20` | 20 | exit status and original `yyerror()`/`syntax_error()` messages |
| Boundary cases | `B01`-`B10` | 10 | empty constructs, shadowing, forward references, and complex declarators |

## Run

From `w4-1/`:

```sh
./tests/run.sh
```

The runner builds with these commands; it never invokes Make:

```sh
bison -d -o y.tab.c c.y
flex -o lex.yy.c c.l
gcc -o parser y.tab.c lex.yy.c support.c print.c main.c
```

List or select tests with:

```sh
./tests/run.sh list
./tests/run.sh ast
./tests/run.sh A01
./tests/run.sh error --no-build
```

Selectors are `all`, `parse`, `ast`, `error`, `boundary`, or one case ID.
`--no-build` reuses an existing `parser` executable.

## Assertions

`cases.tsv` is the test manifest. Normal and boundary cases require exit code
0, a complete syntax-tree header, `N_PROGRAM`, no printer error marker, and
case-specific output fragments. Error cases require exit code 1, the exact
original diagnostic fragment, and no AST output.

AST output contains process-dependent pointer addresses. The runner normalizes
hexadecimal addresses and `(nil)` to `<ADDR>`, then extracts every `N_*` node
as `depth:node-name`. It compares the complete extracted sequence with the
corresponding file under `expected/ast/`. The depth and preorder sequence
therefore verify both parent-child relationships and operator precedence.

On failure the runner prints the source input, expected exit/output or node
tree, actual exit status, and normalized parser output. Build failures are
reported separately as environment/build problems.

## Textbook limitations represented by the suite

The grammar requires declarations before statements in a compound block,
treats a named `void` parameter as error 14, and has no dedicated lexer error
handler for otherwise unmatched characters. The suite does not reinterpret
these behaviors or extend the grammar. Error `E10` records the original
cascading diagnostics 21 and 31, while `E16` records diagnostics 11 and 32.
