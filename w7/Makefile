CC ?= cc
BISON ?= bison
FLEX ?= flex
PYTHON ?= python3

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I.
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic -O0 -g

TARGET := parser
GENERATED := y.tab.c y.tab.h lex.yy.c
SOURCES := y.tab.c lex.yy.c support.c print.c semantic.c print_sem.c main.c
OBJECTS := $(SOURCES:.c=.o)
HEADERS := type.h support.h

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

y.tab.c: c.y
	@$(BISON) -d -o $@ $<

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	@$(FLEX) -o $@ $<

$(OBJECTS): $(HEADERS)

lex.yy.o: CFLAGS += -Wno-sign-compare

test:
	@$(PYTHON) tests/ch7/run.py

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJECTS) $(GENERATED)
