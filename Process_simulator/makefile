# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Target name
TARGET = lab02

# Source file
SRC = lab02.c

# Default rule
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up compiled files
clean:
	rm -f $(TARGET)
