@echo off
setlocal EnableExtensions

set "ROOT=%~dp0"
set "BUILD_LOG=%ROOT%build.log"
set "STEP_LOG=%ROOT%.build-step.log"
set "EXIT_CODE=0"

if "%~1"=="" (
    set "INPUT_FILE=%ROOT%tests\ast\cases\01_integer.c"
) else if exist "%~f1" (
    set "INPUT_FILE=%~f1"
) else (
    set "INPUT_FILE=%ROOT%%~1"
)

pushd "%ROOT%" >nul
if errorlevel 1 (
    echo [ERROR] Failed to enter the w4 directory: "%ROOT%" 1>&2
    exit /b 1
)

if not exist "%INPUT_FILE%" (
    echo [ERROR] Input file not found: "%INPUT_FILE%" 1>&2
    set "EXIT_CODE=1"
    goto :finish
)

set "PARSER_ARGS="
for %%F in ("%INPUT_FILE%") do set "INPUT_NAME=%%~nxF"
if /I "%INPUT_NAME%"=="03_precedence.c" set "PARSER_ARGS=--ast-test precedence"
if /I "%INPUT_NAME%"=="04_parentheses.c" set "PARSER_ARGS=--ast-test parentheses"

type nul > "%BUILD_LOG%"

call :run_logged bison -y -d "%ROOT%c.y"
if errorlevel 1 (
    set "EXIT_CODE=%ERRORLEVEL%"
    echo [ERROR] bison failed. See "%BUILD_LOG%". 1>&2
    goto :finish
)

call :run_logged flex "%ROOT%c.l"
if errorlevel 1 (
    set "EXIT_CODE=%ERRORLEVEL%"
    echo [ERROR] flex failed. See "%BUILD_LOG%". 1>&2
    goto :finish
)

call :run_logged gcc -Wall -Wextra -std=c11 -g -O0 "%ROOT%y.tab.c" "%ROOT%lex.yy.c" "%ROOT%semantic.c" "%ROOT%syntax_tree.c" "%ROOT%logger.c" "%ROOT%print.c" "%ROOT%tests\ast\ast_assert.c" "%ROOT%tests\ast\ast_options.c" "%ROOT%tests\ast\ast_expression.c" "%ROOT%tests\ast\ast_declaration.c" "%ROOT%tests\ast\ast_statement.c" "%ROOT%tests\ast\ast.c" -o "%ROOT%parser.exe"
if errorlevel 1 (
    set "EXIT_CODE=%ERRORLEVEL%"
    echo [ERROR] gcc failed. See "%BUILD_LOG%". 1>&2
    goto :finish
)

"%ROOT%parser.exe" %PARSER_ARGS% < "%INPUT_FILE%"
if errorlevel 1 (
    set "EXIT_CODE=%ERRORLEVEL%"
    echo [ERROR] Parser test failed: "%INPUT_FILE%" 1>&2
    goto :finish
)

echo [SUCCESS] Parser test passed: "%INPUT_FILE%"

:finish
if exist "%STEP_LOG%" del /q "%STEP_LOG%"
popd
exit /b %EXIT_CODE%

:run_logged
%* > "%STEP_LOG%" 2>&1
set "COMMAND_EXIT=%ERRORLEVEL%"
type "%STEP_LOG%"
type "%STEP_LOG%" >> "%BUILD_LOG%"
exit /b %COMMAND_EXIT%
