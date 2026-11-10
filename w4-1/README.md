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
