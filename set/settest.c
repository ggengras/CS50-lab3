/*
* settest.c  Graeme Gengras, April 2018
*
* Simple testing file for the set module.  See function
* details in set.h.  Each function is tested
* with normal and NULL parameters
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "set.h"

// Item print function
void printint(FILE *fp, const char *key, void *item) {
    int *valuep = item;
    fprintf(fp, "%s:%d", key, *valuep);
}

// Iterate function
void iterateprint(void *arg, const char *key, void *item) {
    int *valuep = item;
    printf("%s:%d", key, *valuep);
}

// Tests
int main(void) {
    // Make a new set
    set_t *set;
    set = set_new();
    assert(set != NULL); // Make sure pointer is good

    // Add a key/value pair to the set
    char *key = "key";
    int value = 5;
    assert(set_insert(set, key, &value) == true);

    // Attempt to add NULLs
    char *keytwo = NULL;
    int *valuetwo = NULL;
    assert(set_insert(set, keytwo, valuetwo) == false);

    // Test finding item with key
    int *foundvalue = set_find(set, key);
    assert(*foundvalue == 5);

    // Test finding NULL key
    assert(set_find(set, NULL) == NULL);

    // Test printing
    printf("Testing set printing\n");
    set_print(set, stdout, printint);

    // Test printing NULL set
    set_print(NULL, stdout, NULL);

    // Test iteration with print function (should do the same thing)
    printf("Testing set iteration\n");
    set_iterate(set, stdout, iterateprint);

    // Test deletion
    set_delete(set, NULL);
    // Check for memory leaks to make sure this was successful

    printf("\nSet Tests Successful\n");
    return 0;
}
