# Semantic tests

This directory contains the semantic-analysis test cases, their test runner,
and platform-specific build entry points.

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
