# Chapter 5 syntax analyzer

This directory is the assignment baseline derived from the photographed
appendix programs in `img/`.

The assignment-specific version intentionally omits:

- declarator and enum initializers;
- all storage classes (`auto`, `static`, `typedef`, `extern`, `register`);
- semantic-analysis and code-generation phases from Appendix A9;
- assembly output and other later-phase state.

`initialize()` remains because the lexer and parser need the primitive type
and predefined-identifier tables. `type.h` keeps the complete Appendix A1
data structures even when some fields are unused. `print.c` is based on the
separately provided Appendix A5 printer, with initializer and storage-class
printing branches removed for this assignment subset.

`YYSTYPE` is `long` on LP64 Unix and `long long` on 64-bit Windows, where
`long` is only four bytes. Both the lexer and parser use a static assertion to
ensure that the semantic value can hold a pointer.

## Build

Unix/MSYS2:

```sh
make
./parser < source.c
```

Windows `cmd.exe`:

```bat
parser.cmd
parser.exe < source.c
```

PowerShell:

```powershell
Get-Content -Raw source.c | .\parser.exe
```

The one Bison shift/reduce conflict is the conventional dangling-`else`
conflict and resolves by shifting `else` to the nearest unmatched `if`.
