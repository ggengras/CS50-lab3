# Graeme Gengras, April 2018
#
# Makefile for the 'counter' data structure
#   Build, compiles and tests the module

# Compiler and flags
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -ggdb
PROG = hashtable
TEST= $(PROG)test
OBJS= hashtable.o jhash.o

.PHONY: test clean

all: hashtable.o jhash.o

# Target dependencies
hashtable.o: hashtable.h ../set/set.h
jhash.o: jhash.h

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST).c ../set/set.c -o $(TEST)
	./$(TEST)

clean:
	rm -f *~ *.o
	rm -rf *.dSYM
	rm -f $(TEST)
