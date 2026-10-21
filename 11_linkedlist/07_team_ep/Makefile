# Implementation choice (IMPL) lives in config.mk
include config.mk

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files: main.c never changes; only the TeamList implementation does
SRCS = main.c team.c teamlist_$(IMPL).c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = team_ep

# Phony targets
.PHONY: all compile run clean

# Default target (compile and run)
all: compile run

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up (both implementations)
clean:
	rm -f *.o $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files; relink whenever config.mk changes
$(TARGET): $(OBJS) config.mk
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
