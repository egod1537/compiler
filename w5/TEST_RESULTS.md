# Previous syntax-analyzer test results

> These results describe the earlier assignment-specific subset. They are
> retained as historical notes and no longer describe the photographed
> appendix transcription now in `c.l`, `c.y`, `support.c`, and `main.c`.

Tested on 2026-11-07 after removing assignment-excluded functionality.

## Build and platform checks

- `make`: passed
- macOS clean build with Apple Clang 17 and system Bison 2.3: passed without warnings
- Unix `make test`: 15 passed, 0 failed
- `parser.cmd`: passed
- Windows CRLF input: passed
- Unix LF input: passed
- Bison reports only the expected dangling-`else` shift/reduce conflict

## Assignment-scope probes

| Input feature | Expected | Result |
|---|---|---|
| ordinary function and expression AST | accept and print | passed |
| variadic parameter (`...`) | accept | passed |
| scalar initializer | reject | passed |
| braced initializer | reject | passed |
| enum initializer | reject | passed |
| `auto` | reject | passed |
| `static` | reject | passed |
| `typedef` | reject | passed |
| `extern` | reject | passed |
| `register` | reject | passed |

All rejected probes exited with status 1 and none crashed.

## Imported `w4/tests` corpus

The 139 imported test files remain unmodified. They were written for the GPT
implementation rather than this appendix-based assignment subset.

| Group | Total | Accepted | Rejected | Process crash |
|---|---:|---:|---:|---:|
| `cases` | 63 | 9 | 54 | 0 |
| `valid` | 7 | 0 | 7 | 0 |
| `invalid` | 10 | 0 | 10 | 0 |
| `unsupported` | 8 | 0 | 8 | 0 |

Most GPT-targeted cases declare `main(void)`. Appendix A4 diagnoses a `void`
formal parameter as error 14, so those rejections are retained pending
instructor confirmation. The semantic unit tests target files outside this
syntax-analyzer assignment and are not part of the submission build.
