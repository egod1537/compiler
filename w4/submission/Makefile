CC ?= cc
BISON ?= bison
FLEX ?= flex

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
	main.c
OBJECTS := $(SOURCES:.c=.o)
HEADERS := \
	logger.h \
	parse_value.h \
	semantic.h \
	syntax_tree.h \
	type.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

y.tab.c: c.y
	$(BISON) -y -d c.y

y.tab.h: y.tab.c
	@test -f $@ || $(BISON) -y -d c.y

lex.yy.c: c.l y.tab.h
	$(FLEX) c.l

$(OBJECTS): $(HEADERS)

clean:
	rm -f $(TARGET) $(OBJECTS) $(GENERATED)
