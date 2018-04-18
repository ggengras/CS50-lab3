# Graeme Gengras, April 2018
#
# Makefile for the 'counter' data structure
#   Build, compiles and tests the module

# Compiler and flags
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -ggdb
OBJS=
LIBS=

.PHONY: test clean

all: counter.o

# Target dependencies
counter.o:
	$(CC) $(CFLAGS) -c counters.c

test:
	$(CC) $(CFLAGS) counterstest.c counters.c -o counterstest
	./counterstest

clean:
	rm -f *~ *.o
	rm -rf *.dSYM
	rm -f counterstest
