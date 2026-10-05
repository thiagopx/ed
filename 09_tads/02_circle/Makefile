# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Libraries
LIBS = -lm # math library

# Source directory
SRC_DIR = src

# Header directory
INC_DIR = include

# Executable name
TARGET = test_circle

# Main file
MAIN = test_circle.c

# Source files: all .c files in the source directory plus the main file
SRCS = $(wildcard $(SRC_DIR)/*.c) $(MAIN)

# Object files: replace .c with .o
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Explicit compile target
# By default, the first target (this) is the one that will be executed if no target is specified
compile: $(TARGET)

# Run the program: depends on the target program
run: $(TARGET)
	./$(TARGET)

# Compile and run the program
all: compile run

# Clean up: remove object files and the target program
clean:
	rm -f $(OBJS) $(TARGET)

# Compile each source file into an object file: <file>.o depends on <file>.c
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile source files in the source directory into object files: <source_dir>/<file>.o depends on <source_dir>/<file>.c
# This rule has higher priority than the previous one because it is more specific
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to link object files and create the executable (target): depends on all object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Phony targets: targets that are not files
.PHONY: all compile run clean