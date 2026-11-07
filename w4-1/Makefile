CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -O0 -g
LEX = flex
YACC = bison

.PHONY: all clean

all: parser

y.tab.c y.tab.h: c.y
	$(YACC) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	$(LEX) c.l

parser: y.tab.c lex.yy.c support.c print.c main.c type.h support.h parse_value.h
	$(CC) $(CFLAGS) -o $@ y.tab.c lex.yy.c support.c print.c main.c

clean:
	rm -f parser parser.exe y.tab.c y.tab.h lex.yy.c *.o
