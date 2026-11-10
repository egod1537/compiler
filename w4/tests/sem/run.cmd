@echo off
setlocal EnableExtensions

set "TEST_ROOT=%~dp0"
for %%I in ("%TEST_ROOT%..\..") do set "ROOT=%%~fI"
set "BIN_DIR=%TEST_ROOT%bin"
set "SEM_EXE=%BIN_DIR%\sem_tests.exe"
set "DEBUG_CFLAGS=-Wall -Wextra -std=c11 -g3 -O0 -fno-omit-frame-pointer"

if not exist "%BIN_DIR%" mkdir "%BIN_DIR%"
if errorlevel 1 (
    echo [ERROR] Failed to create test output directory: "%BIN_DIR%" 1>&2
    exit /b 1
)

gcc %DEBUG_CFLAGS% -I"%ROOT%" ^
    "%TEST_ROOT%sem.c" ^
    "%TEST_ROOT%sem_symbol_table.c" ^
    "%TEST_ROOT%sem_type_table.c" ^
    "%TEST_ROOT%sem_scope.c" ^
    "%TEST_ROOT%sem_declarator.c" ^
    "%ROOT%\syntax_tree.c" ^
    "%ROOT%\semantic.c" ^
    "%ROOT%\error.c" ^
    "%ROOT%\logger.c" ^
    -o "%SEM_EXE%"
if errorlevel 1 (
    echo [ERROR] Semantic test build failed. 1>&2
    exit /b %errorlevel%
)

"%SEM_EXE%" %*
exit /b %errorlevel%
