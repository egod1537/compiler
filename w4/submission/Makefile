CC ?= gcc
BISON ?= bison
FLEX ?= flex

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

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

y.tab.c: c.y
	$(BISON) -d -o y.tab.c c.y

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -d -o y.tab.c c.y

lex.yy.c: c.l y.tab.h
	$(FLEX) c.l

$(OBJECTS): $(HEADERS)

lex.yy.o: CFLAGS += -Wno-sign-compare

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJECTS) $(GENERATED)
