@echo off
setlocal

set "ROOT=%~dp0"
python -B "%ROOT%tests\parse_ast.py" %*
exit /b %errorlevel%

