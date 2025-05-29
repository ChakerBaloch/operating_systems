# Makefile for CPU Scheduling Simulator

CC = gcc
CFLAGS = -Wall -g

# Targets
all: SJF RR

SJF: SJF_inital.c
	$(CC) $(CFLAGS) SJF_inital.c -o SJF

RR: RR_inital.c
	$(CC) $(CFLAGS) RR_inital.c -o RR

clean:
	rm -f SJF RR
