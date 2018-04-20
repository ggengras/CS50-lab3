# CS50 Lab 3 - Counters
## Graeme Gengras, April 2018

### Counters Testing
To test the `counters` module, I wrote a simple program called `counterstest.c` which can be compiled and executed with the command `make test`. `counterstest.c` tests the functionality of each method exported by `counters.h`, mainly by using `assert.h` to ensure functions return what they should in a variety of circumstances.  See `counterstest.c` for more detail about what functionality is being tested.

### Test run
Execution of the testing is shown below. Some output occurs to test the logic in `counterstest.c`, and if all tests were successful then the final line of the program "Counters Tests Successful" is printed to stdout and the program returns 0.

```
[ggengras@moose ~/cs50/labs/lab3/counters]$ make test
gcc -Wall -pedantic -std=c11 -ggdb counters.o counterstest.c -o counterstest
./counterstest
Testing counter set printing
{20002:10,10001:1}
Testing NULL counter set printing
(NULL)
Testing iteration (with printing)
20002:10
10001:1
Counters Tests Successful
```

### Valgrind Output
To make sure that `counters` allocates and frees memory properly, I also ran `counterstest` with Valgrind.

```
[ggengras@moose ~/cs50/labs/lab3/counters]$ valgrind ./counterstest
==28648== Memcheck, a memory error detector
==28648== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==28648== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==28648== Command: ./counterstest
==28648==
Testing counter set printing
{20002:10,10001:1}
Testing NULL counter set printing
(NULL)
Testing iteration (with printing)
20002:10
10001:1
Counters Tests Successful
==28648==
==28648== HEAP SUMMARY:
==28648==     in use at exit: 0 bytes in 0 blocks
==28648==   total heap usage: 4 allocs, 4 frees, 1,064 bytes allocated
==28648==
==28648== All heap blocks were freed -- no leaks are possible
==28648==
==28648== For counts of detected and suppressed errors, rerun with: -v
==28648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
