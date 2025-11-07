# Makefile for paroot Library

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -Ilib
AR = ar
ARFLAGS = rcs
LDFLAGS = -Llib -lparoot

# Library files
LIB = lib/libparoot.a
OBJS = lib/paroot.o

# Find all .c files (excluding lib directory) for shell completion
C_FILES := $(shell find . -name "*.c" -not -path "./lib/*" -print)
# Convert to target names (without .c extension and without ./ prefix)
C_TARGETS := $(patsubst ./%.c,%,$(C_FILES))

.PHONY: all clean example help list-dynamic-targets

all: $(LIB)

# Build the paroot library
$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

lib/paroot.o: lib/paroot.c lib/paroot.h
	$(CC) $(CFLAGS) -c lib/paroot.c -o lib/paroot.o

# Universal dynamic target: compile any .c file anywhere in the tree
# Usage: make test (compiles test.c -> test)
#        make lecture1/kurac/test (compiles lecture1/kurac/test.c -> lecture1/kurac/test)
#        make 2025-26/lecture1/hello (compiles 2025-26/lecture1/hello.c -> 2025-26/lecture1/hello)
%: %.c $(LIB)
	@echo "Compiling $< with paroot library..."
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
	@echo "Success! Run with: ./$@"

# List all dynamic targets for shell completion
list-dynamic-targets:
	@echo $(C_TARGETS)

# Help target
help:
	@echo "paroot Library Makefile"
	@echo "====================="
	@echo ""
	@echo "Usage:"
	@echo "  make                    - Build the paroot library"
	@echo "  make <path/to/file>     - Compile any .c file with paroot library"
	@echo "  make clean              - Remove all build artifacts"
	@echo "  make help               - Show this help message"
	@echo "  make list-dynamic-targets - List all compilable C files"
	@echo ""
	@echo "Examples:"
	@echo "  make test                    - Compiles test.c -> test"
	@echo "  make lecture1/test           - Compiles lecture1/test.c -> lecture1/test"
	@echo "  make lecture1/kurac/test     - Compiles lecture1/kurac/test.c -> lecture1/kurac/test"
	@echo "  make 2025-26/lecture1/hello  - Compiles 2025-26/lecture1/hello.c -> 2025-26/lecture1/hello"

clean:
	rm -f $(OBJS) $(LIB) example
	@echo "Cleaned build artifacts"
