@echo off
setlocal
cd /d "%~dp0"

bison -d -o y.tab.c c.y || exit /b 1
flex c.l || exit /b 1
gcc -std=c11 -Wall -Wextra -pedantic -O0 -g -o parser.exe y.tab.c lex.yy.c support.c print.c main.c || exit /b 1

echo Built %CD%\parser.exe
