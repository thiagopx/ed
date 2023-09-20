# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files
SRCS = main.c my_string.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = my_program

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

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
