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

all: hashtable.o

# Target dependencies
hashtable.o:
	$(CC) $(CFLAGS) -c hashtable.c ../set/set.c

test:
	$(CC) $(CFLAGS) hashtabletest.c hashtable.c -o hashtabletest
	./hashtabletest

clean:
	rm -f *~ *.o
	rm -rf *.dSYM
	rm -f hashtabletest
