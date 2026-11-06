CC ?= cc
BISON ?= bison
FLEX ?= flex
TEST ?=
MAKEFLAGS += --no-print-directory

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I.
CFLAGS ?= -Wall -Wextra -std=c11 -O2

TARGET := parser
GENERATED := y.tab.c y.tab.h lex.yy.c
SOURCES := \
	y.tab.c \
	lex.yy.c \
	semantic.c \
	syntax_tree.c \
	logger.c \
	print.c \
	tests/ast/ast_assert.c \
	tests/ast/ast_options.c \
	tests/ast/ast_expression.c \
	tests/ast/ast_declaration.c \
	tests/ast/ast_statement.c \
	tests/ast/ast_expected.c \
	tests/ast/ast.c
OBJECTS := $(SOURCES:.c=.o)
HEADERS := \
	logger.h \
	parse_value.h \
	semantic.h \
	syntax_tree.h \
	type.h \
	tests/ast/ast_assert.h \
	tests/ast/ast_expected.h \
	tests/ast/ast_runner.h

.PHONY: all clean print-ast test test-ast test-ast-exp test-parser test-sem

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

y.tab.c: c.y
	@$(BISON) -y -d c.y

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -y -d c.y

lex.yy.c: c.l y.tab.h
	@$(FLEX) c.l

$(OBJECTS): $(HEADERS)

test: $(TARGET)
	@status=0; \
	$(MAKE) test-ast || status=1; \
	$(MAKE) test-ast-exp || status=1; \
	$(MAKE) test-sem || status=1; \
	exit $$status

test-ast: $(TARGET)
	@bash tests/ast/run.sh ./$(TARGET) $(TEST)

test-ast-exp: $(TARGET)
	@bash tests/ast/run_expected.sh ./$(TARGET) $(TEST)

test-parser: test-ast

test-sem:
	@$(MAKE) -C tests/sem test TEST="$(TEST)"

print-ast: $(TARGET)
	@bash tests/ast/print.sh ./$(TARGET) "$(FILE)"

clean:
	rm -f $(TARGET) $(OBJECTS) $(GENERATED)
	$(MAKE) -C tests/sem clean
