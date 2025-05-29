# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Build both programs
all: SJF RR

# Compile SJF
SJF: SJF_inital.c
	$(CC) $(CFLAGS) SJF_inital.c -o SJF

# Compile RR
RR: RR_inital.c
	$(CC) $(CFLAGS) RR_inital.c -o RR

# Remove compiled files
clean:
	rm -f SJF RR

