# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source directory
SRC_DIR = source

# Header directory
INC_DIR = headers

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

# Executable name
TARGET = test_circle

# Compile source files into object files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all compile run clean

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Default target (compile and run)
all: compile run

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
