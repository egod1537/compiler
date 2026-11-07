CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -O0 -g
LEX = flex
YACC = bison
TEST ?=
MAKEFLAGS += --no-print-directory

.PHONY: all clean print-ast test test-ch5 test-ast test-astexp \
	test-ast-exp test-parser test-sem test-semerr

all: parser

y.tab.c y.tab.h: c.y
	$(YACC) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	$(LEX) c.l

parser: y.tab.c lex.yy.c support.c error.c print.c main.c type.h support.h error.h parse_value.h
	$(CC) $(CFLAGS) -o $@ y.tab.c lex.yy.c support.c error.c print.c main.c

test: parser
	@status=0; \
	$(MAKE) test-ch5 || status=1; \
	$(MAKE) test-ast || status=1; \
	$(MAKE) test-astexp || status=1; \
	$(MAKE) test-sem || status=1; \
	$(MAKE) test-semerr || status=1; \
	exit $$status

test-ch5: parser
	@bash tests/ch5/run.sh ./parser

test-ast: parser
	@bash tests/ast/run.sh ./parser $(if $(TEST),$(TEST),all)

test-astexp: parser
	@bash tests/ast/run_expected.sh ./parser $(if $(TEST),$(TEST),all)

test-ast-exp: test-astexp

test-parser: test-ast

test-sem:
	@$(MAKE) -C tests/sem test TEST="$(TEST)"

test-semerr: parser
	@bash tests/semerr/run.sh ./parser $(if $(TEST),$(TEST),all)

print-ast: parser
	@bash tests/ast/print.sh ./parser "$(FILE)"

clean:
	rm -f parser parser.exe y.tab.c y.tab.h lex.yy.c *.o
	rm -f tests/ast/*.o
	@$(MAKE) -C tests/sem clean
