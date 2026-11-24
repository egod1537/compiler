# SEMERR integration tests

SEMERR feeds real C source files to the generated Lex/Yacc parser. It checks
the first stable error tag (`CLASS` and lecture error code), rather than the
entire human-readable message.

```sh
make test-semerr
make test-semerr TEST=1
make test-semerr TEST=list
```

Cases 1-10 cover Chapter 5 declaration checks. Cases 11-14 prevent false
positives for shadowing, completed forward references, compatible function
declarations, and `void` parameter lists. Cases 15-16 verify syntax and lexical
classification. Chapter 7 expression/type semantic analysis is intentionally
outside this suite.
