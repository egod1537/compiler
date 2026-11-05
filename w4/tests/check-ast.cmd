@echo off
setlocal

set "ROOT=%~dp0.."
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%ROOT%\tools\check-ast.ps1" %*
exit /b %errorlevel%
