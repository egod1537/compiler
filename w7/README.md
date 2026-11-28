# Photographed appendix transcription

The photographed Appendix A2, A3, A4, and A9 programs in `img/` are restored
in `c.l`, `c.y`, `support.c`, and `main.c`. This includes storage classes,
declarator and enum initializers, specifier merging, assembly-file setup, and
the semantic-analysis/code-generation calls shown in the photographs.

## Build status

The files are a literal transcription of the photographed legacy source. The
A9 main program refers to `semantic_err`, `semantic_analysis()`, and
`code_generation()`, whose appendix implementations are not present in the
photographed file set. No pointer-width or modern-toolchain compatibility
layer is included; the source retains the original yacc `int` semantic-value
assumptions shown in the photographs.

The one Bison shift/reduce conflict is the conventional dangling-`else`
conflict and resolves by shifting `else` to the nearest unmatched `if`.

## Assignment 7 semantic tests

Run the semantic-analysis suite from this directory with `make test`. The suite
contains 49 Assignment 7 cases and 47 Assignment 6 regression cases. The
remaining Assignment 7 IDs are not renumbered: TC01 through TC47 are followed
by TC50 and TC51.

TC48 (duplicate `case`), TC49 (duplicate `default`), and CH6-5-10 (a pointer to
an incomplete structure) are outside the supported scope of the textbook-based
implementation and are excluded from the test sources and execution lists. No
compiler implementation change was made for these exclusions. See
[`tests/ch7/README.md`](tests/ch7/README.md) and
[`tests/ch7/RESULTS.md`](tests/ch7/RESULTS.md) for the test definition and the
latest execution results.
