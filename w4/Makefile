CC ?= gcc
BISON ?= bison
FLEX ?= flex
TEST ?=
MAKEFLAGS += --no-print-directory

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I.
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -O0 -g

TARGET := parser
AST_TARGET := tests/bin/ast_parser
GENERATED := y.tab.c y.tab.h lex.yy.c
CORE_SOURCES := \
	y.tab.c \
	lex.yy.c \
	semantic.c \
	syntax_tree.c \
	error.c \
	print.c
PARSER_SOURCES := $(CORE_SOURCES) main.c
AST_TEST_SOURCES := \
	logger.c \
	tests/ast/ast_assert.c \
	tests/ast/ast_options.c \
	tests/ast/ast_expression.c \
	tests/ast/ast_declaration.c \
	tests/ast/ast_statement.c \
	tests/ast/ast_expected.c \
	tests/ast/ast.c
AST_SOURCES := $(CORE_SOURCES) $(AST_TEST_SOURCES)
CORE_OBJECTS := $(CORE_SOURCES:.c=.o)
PARSER_OBJECTS := $(PARSER_SOURCES:.c=.o)
AST_TEST_OBJECTS := $(AST_TEST_SOURCES:.c=.o)
AST_OBJECTS := $(AST_SOURCES:.c=.o)
CORE_HEADERS := \
	error.h \
	parse_value.h \
	semantic.h \
	syntax_tree.h \
	type.h
AST_HEADERS := \
	logger.h \
	tests/ast/ast_assert.h \
	tests/ast/ast_expected.h \
	tests/ast/ast_runner.h

.PHONY: all clean print-ast test test-baseline test-ch5 test-ast test-astexp \
	test-ast-exp test-parser test-sem test-semerr

all: $(TARGET)

$(TARGET): $(PARSER_OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $(PARSER_OBJECTS) $(LDLIBS)

$(AST_TARGET): $(AST_OBJECTS)
	@mkdir -p $(@D)
	@$(CC) $(LDFLAGS) -o $@ $(AST_OBJECTS) $(LDLIBS)

y.tab.c: c.y
	@$(BISON) -d -o y.tab.c c.y

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	@$(FLEX) c.l

$(CORE_OBJECTS) main.o: $(CORE_HEADERS)

$(AST_TEST_OBJECTS): $(CORE_HEADERS) $(AST_HEADERS)

test: $(TARGET)
	@status=0; \
	$(MAKE) test-ch5 || status=1; \
	$(MAKE) test-ast || status=1; \
	$(MAKE) test-astexp || status=1; \
	$(MAKE) test-sem || status=1; \
	$(MAKE) test-semerr || status=1; \
	$(MAKE) test-baseline || status=1; \
	exit $$status

test-baseline: $(TARGET)
	@$(MAKE) -C ../w4-1
	@status=0; bash tests/baseline/run.sh ./$(TARGET) ../w4-1/parser || status=$$?; \
	$(MAKE) -C ../w4-1 clean; exit $$status

test-ch5: $(TARGET)
	@bash tests/ch5/run.sh ./$(TARGET)

test-ast: $(AST_TARGET)
	@bash tests/ast/run.sh ./$(AST_TARGET) $(TEST)

test-astexp: $(AST_TARGET)
	@bash tests/ast/run_expected.sh ./$(AST_TARGET) $(TEST)

test-ast-exp: test-astexp

test-parser: test-ast

test-sem:
	@$(MAKE) -C tests/sem test TEST="$(TEST)"

test-semerr: $(TARGET)
	@bash tests/semerr/run.sh ./$(TARGET) $(if $(TEST),$(TEST),all)

print-ast: $(TARGET)
	@bash tests/ast/print.sh ./$(TARGET) "$(FILE)"

clean:
	rm -f $(TARGET) $(TARGET).exe $(AST_TARGET) $(AST_TARGET).exe \
		$(sort $(PARSER_OBJECTS) $(AST_OBJECTS)) $(GENERATED) build.log
	$(MAKE) -C tests/sem clean
