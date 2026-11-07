CC ?= cc
TEST ?=

ROOT := ../..
FIXTURE_ROOT := $(ROOT)/submission
TARGET := bin/sem_tests
TEST_SOURCES := \
	sem.c \
	sem_symbol_table.c \
	sem_type_table.c \
	sem_scope.c \
	sem_declarator.c
PROJECT_SOURCES := \
	$(FIXTURE_ROOT)/syntax_tree.c \
	$(FIXTURE_ROOT)/semantic.c \
	$(FIXTURE_ROOT)/logger.c
HEADERS := \
	$(FIXTURE_ROOT)/logger.h \
	$(FIXTURE_ROOT)/semantic.h \
	$(FIXTURE_ROOT)/syntax_tree.h \
	$(FIXTURE_ROOT)/type.h

CPPFLAGS += -D_POSIX_C_SOURCE=200809L -I$(FIXTURE_ROOT)
CFLAGS ?= -Wall -Wextra -std=c11 -g3 -O0 -fno-omit-frame-pointer

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(TEST_SOURCES) $(PROJECT_SOURCES) $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(TEST_SOURCES) $(PROJECT_SOURCES) -o $@ $(LDLIBS)

test: $(TARGET)
	@./$(TARGET) $(TEST)

clean:
	rm -f $(TARGET) $(TARGET).exe bin/sem_compat_tests bin/sem_compat_tests.exe
	@rmdir bin 2>/dev/null || true
