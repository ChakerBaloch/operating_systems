# Makefile

CC = gcc                   # Compiler to use
CFLAGS = -Wall -g          # Show all warnings and include debug symbols

# Default target: build the final executable
all: Chaker_testapp

# Link object files into the executable
Chaker_testapp: Chaker_testFS.o Chaker_libFS.o
	$(CC) $(CFLAGS) -o Chaker_testapp Chaker_testFS.o Chaker_libFS.o

# Compile test file to object file
Chaker_testFS.o: Chaker_testFS.c Chaker_libFS.h
	$(CC) $(CFLAGS) -c Chaker_testFS.c

# Compile libFS implementation to object file
Chaker_libFS.o: Chaker_libFS.c Chaker_libFS.h
	$(CC) $(CFLAGS) -c Chaker_libFS.c

# Clean up generated files
clean:
	rm -f *.o Chaker_testapp
