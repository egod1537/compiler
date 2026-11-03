@echo off
setlocal

set "ROOT=%~dp0"

if exist "%ROOT%semantic.c" (
    gcc -Wall -Wextra -std=c11 "%ROOT%test.c" "%ROOT%syntax_tree.c" "%ROOT%semantic.c" -o "%ROOT%test.exe"
) else (
    gcc -Wall -Wextra -std=c11 "%ROOT%test.c" "%ROOT%syntax_tree.c" -o "%ROOT%test.exe"
)
if errorlevel 1 exit /b %errorlevel%

"%ROOT%test.exe"
exit /b %errorlevel%
