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

type nul > "%BUILD_LOG%"

call :run_logged bison -d -o "%ROOT%y.tab.c" "%ROOT%c.y"
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

call :run_logged gcc -Wall -Wextra -std=c11 -g -O0 "%ROOT%y.tab.c" "%ROOT%lex.yy.c" "%ROOT%semantic.c" "%ROOT%syntax_tree.c" "%ROOT%error.c" "%ROOT%print.c" "%ROOT%main.c" -o "%ROOT%parser.exe"
if errorlevel 1 (
    set "EXIT_CODE=%ERRORLEVEL%"
    echo [ERROR] gcc failed. See "%BUILD_LOG%". 1>&2
    goto :finish
)

"%ROOT%parser.exe" < "%INPUT_FILE%"
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
