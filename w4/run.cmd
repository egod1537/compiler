@echo off
setlocal

set "ROOT=%~dp0"
set "DEBUG_CFLAGS=-Wall -Wextra -std=c11 -g3 -O0 -fno-omit-frame-pointer"

if exist "%ROOT%semantic.c" (
    gcc %DEBUG_CFLAGS% "%ROOT%test.c" "%ROOT%syntax_tree.c" "%ROOT%semantic.c" -o "%ROOT%test.exe"
) else (
    gcc %DEBUG_CFLAGS% "%ROOT%test.c" "%ROOT%syntax_tree.c" -o "%ROOT%test.exe"
)
if errorlevel 1 exit /b %errorlevel%

"%ROOT%test.exe"
exit /b %errorlevel%
