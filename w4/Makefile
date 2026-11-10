CC ?= gcc
BISON ?= bison
FLEX ?= flex
TEST ?=
MAKEFLAGS += --no-print-directory

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I.
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -O0 -g

TARGET := parser
GENERATED := y.tab.c y.tab.h lex.yy.c
SOURCES := \
	y.tab.c \
	lex.yy.c \
	semantic.c \
	syntax_tree.c \
	error.c \
	print.c \
	main.c
OBJECTS := $(SOURCES:.c=.o)
HEADERS := \
	error.h \
	parse_value.h \
	semantic.h \
	syntax_tree.h \
	type.h

.PHONY: all clean test test-ch5 test-ast test-sem test-semerr

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

y.tab.c: c.y
	@$(BISON) -d -o y.tab.c c.y

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	@$(FLEX) c.l

$(OBJECTS): $(HEADERS)

lex.yy.o: CFLAGS += -Wno-sign-compare

test: $(TARGET)
	@status=0; \
	$(MAKE) test-ch5 || status=1; \
	$(MAKE) test-ast || status=1; \
	$(MAKE) test-sem || status=1; \
	$(MAKE) test-semerr || status=1; \
	exit $$status

test-ch5: $(TARGET)
	@bash tests/ch5/run.sh ./$(TARGET)

test-ast: $(TARGET)
	@bash tests/ast/run.sh ./$(TARGET) $(TEST)

test-sem:
	@$(MAKE) -C tests/sem test TEST="$(TEST)"

test-semerr: $(TARGET)
	@bash tests/semerr/run.sh ./$(TARGET) $(if $(TEST),$(TEST),all)

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJECTS) $(GENERATED) build.log \
		tests/sem/bin/sem_tests tests/sem/bin/sem_tests.exe
