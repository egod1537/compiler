@echo off
setlocal

set "ROOT=%~dp0"
python -B "%ROOT%tests\verify_ast.py" %*
exit /b %errorlevel%

