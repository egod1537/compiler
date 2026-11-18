# AST manual answers

Each implemented test has two files:

- `NN_name.txt`: the human-written derivation and explanatory comments.
- `NN_name.json`: the same answer as an object graph for `../check.cmd`.

The checker never compares prose or comments from the TXT file. JSON `ref` entries encode
`A_ID`, `A_TYPE`, symbol-reference, shared-type, and recursive-type relationships without
copying runtime pointer values.

Run one test or all numbered inputs from the repository root:

```powershell
.\tests\ast\check.cmd 24
.\tests\ast\check.cmd 24 --diff
.\tests\ast\check.cmd --all
```

Inputs without a manual TXT/JSON answer are reported as `UNVERIFIABLE`, never `PASS`.

The PowerShell-only verifier regression suite is:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\tests\ast\checker_tests.ps1
```
