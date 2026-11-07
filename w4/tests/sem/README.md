# Semantic tests

This directory contains the semantic-analysis test cases, their test runner,
and platform-specific build entry points.

These are the pre-existing unit tests for the earlier GPT semantic helper API.
They build against the preserved implementation in `../../submission` so that
the Chapter 5 parser remains free of the later semantic-analysis layer. Real C
input and the active parser's Chapter 5 declaration checks are covered by the
separate `../semerr` integration suite.

Build and run on Unix-like systems:

```sh
make test
```

From the project root, list stable test numbers or run one test with the same
interface used by the AST suites:

```sh
make test-sem TEST=list
make test-sem TEST=4
```

번호는 코드의 함수명과 직접 대응한다. 예를 들어 `TEST=4`는
`SEM_04_Scope()`를 실행한다.

Build and run on Windows:

```powershell
.\run.cmd
```

Run `make clean` to remove the Unix test binary.
