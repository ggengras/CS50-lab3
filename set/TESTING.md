# CS50 Lab 3 - Set
## Graeme Gengras, April 2018

### Set Testing
To test the `set` module, I wrote a simple program called `settest.c` which can be compiled and executed with the command `make test`. `settest.c` tests the functionality of each method exported by `set.h`, mainly by using `assert.h` to ensure functions return what they should in a variety of circumstances.  See `settest.c` for more detail about what functionality is being tested.

### Test run
Execution of the testing is shown below. Some output occurs to test the logic in `settest.c`, and if all tests were successful then the final line of the program "Set Tests Successful" is printed to stdout and the program returns 0.

```
Graemes-MacBook-Pro:set Graeme$ make test
gcc -Wall -pedantic -std=c11 -ggdb  -c -o set.o set.c
gcc -Wall -pedantic -std=c11 -ggdb set.o settest.c -o settest
./settest
Testing set printing
{key:5}
(NULL)
Testing set iteration
key:5
Set Tests Successful
```

### Valgrind Output
To make sure that `set` allocates and frees memory properly, I also ran `settest` with Valgrind.

```
[ggengras@moose ~/cs50/labs/lab3/set]$ valgrind ./settest
==27491== Memcheck, a memory error detector
==27491== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==27491== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==27491== Command: ./settest
==27491==
Testing set printing
{key:5}
(NULL)
Testing set iteration
key:5
Set Tests Successful
==27491==
==27491== HEAP SUMMARY:
==27491==     in use at exit: 0 bytes in 0 blocks
==27491==   total heap usage: 4 allocs, 4 frees, 1,060 bytes allocated
==27491==
==27491== All heap blocks were freed -- no leaks are possible
==27491==
==27491== For counts of detected and suppressed errors, rerun with: -v
==27491== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
