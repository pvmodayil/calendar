# Makefile

# Compiler
CC=g++

# Compiler flags
CFLAGS=-I.

# Header dependencies
DEPS = calendar.h

# Object files
OBJ = main.o calendar.o

# Default target
all: calendar.exe

# Build the final executable
calendar.exe: $(OBJ)
    $(CC) -o $@ $^

# Pattern rule for building object files from source files
%.o: %.cpp $(DEPS)
    $(CC) -c $< 

# Clean up generated files
clean:
    rm -f *.o calendar.exe 