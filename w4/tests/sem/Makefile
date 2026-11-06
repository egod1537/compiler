CC ?= cc

ROOT := ../..
TARGET := bin/sem_tests
TEST_SOURCES := \
	sem.c \
	sem_symbol_table.c \
	sem_type_table.c \
	sem_scope.c \
	sem_declarator.c
PROJECT_SOURCES := \
	$(ROOT)/syntax_tree.c \
	$(ROOT)/semantic.c \
	$(ROOT)/logger.c
HEADERS := \
	$(ROOT)/logger.h \
	$(ROOT)/semantic.h \
	$(ROOT)/syntax_tree.h \
	$(ROOT)/type.h

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I$(ROOT)
CFLAGS ?= -Wall -Wextra -std=c11 -g3 -O0 -fno-omit-frame-pointer

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(TEST_SOURCES) $(PROJECT_SOURCES) $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(TEST_SOURCES) $(PROJECT_SOURCES) -o $@ $(LDLIBS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	@rmdir bin 2>/dev/null || true
