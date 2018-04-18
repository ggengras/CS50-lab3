# Graeme Gengras, April 2018
#
# Makefile for the 'set' data structure
#   Build, compiles and tests the module

# Compiler and flags
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -ggdb
PROG = set
TEST= $(PROG)test
OBJS= $(PROG).o

.PHONY: test clean

all: $(PROG).o

# Target dependencies
set.o: $(PROG).h

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST).c -o $(TEST)
	./$(TEST)

clean:
	rm -f *~ *.o
	rm -rf *.dSYM
	rm -f $(TEST)
