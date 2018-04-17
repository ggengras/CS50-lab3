# Graeme Gengras, April 2018
#
# Makefile for the 'set' data structure
#   Build, compiles and tests the module

# Compiler and flags
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -ggdb
OBJS=
LIBS=

.PHONY: test clean

all: set.o

# Target dependencies
set.o:
	$(CC) $(CFLAGS) -c set.c

test:
	$(CC) $(CFLAGS) settest.c set.c -o settest
	./settest

clean:
	rm -f *~ *.o
	rm -rf *.dSYM
	rm -f settest
