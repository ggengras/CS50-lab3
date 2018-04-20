# CS50 Lab 3 - Hashtable
## Graeme Gengras, April 2018

### Hashtable Testing
To test the `hashtable` module, I wrote a simple program called `hashtabletest.c` which can be compiled and executed with the command `make test`. `hashtabletest.c` tests the functionality of each method exported by `hashtable.h`, mainly by using `assert.h` to ensure functions return what they should in a variety of circumstances.  See `hashtabletest.c` for more detail about what functionality is being tested.

### Test run
Execution of the testing is shown below. Some output occurs to test the logic in `hashtabletest.c`, and if all tests were successful then the final line of the program "Hashtable Tests Successful" is printed to stdout and the program returns 0.

```
[ggengras@moose ~/cs50/labs/lab3/hashtable]$ make test
gcc -Wall -pedantic -std=c11 -ggdb hashtable.o jhash.o hashtabletest.c ../set/set.c -o hashtabletest
./hashtabletest
Test printing
Slot 0:{}

Slot 1:{}

Slot 2:{}

Slot 3:{}

...

Slot 97:{}

Slot 98:{}

Slot 99:{}

Hashtable Tests Successful
```

### Valgrind Output
To make sure that `hashtable` allocates and frees memory properly, I also ran `hashtabletest` with Valgrind.

```
[ggengras@moose ~/cs50/labs/lab3/hashtable]$ valgrind ./hashtabletest
==28881== Memcheck, a memory error detector
==28881== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==28881== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==28881== Command: ./hashtabletest
==28881==
Test printing
Slot 0:{}

Slot 1:{}

Slot 2:{}

Slot 3:{}

...

Slot 97:{}

Slot 98:{}

Slot 99:{}

Hashtable Tests Successful
==28881==
==28881== HEAP SUMMARY:
==28881==     in use at exit: 0 bytes in 0 blocks
==28881==   total heap usage: 105 allocs, 105 frees, 2,671 bytes allocated
==28881==
==28881== All heap blocks were freed -- no leaks are possible
==28881==
==28881== For counts of detected and suppressed errors, rerun with: -v
==28881== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
