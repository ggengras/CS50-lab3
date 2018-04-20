/*
* counters.c  Graeme Gengras, April 2018
*
* Simple testing file for the hashtable module.  See function
* details in hashtable.h.  Each function is tested
* with normal and NULL parameters
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "hashtable.h"

// Item print function
void printint(FILE *fp, const char *key, void *item) {
    int *valuep = item;
    fprintf(fp, "%s:%d", key, *valuep);
}

// Iterate function
void iterateprint(void *arg, const char *key, void *item) {
    int *valuep = item;
    printf("%s:%d\n", key, *valuep);
}

// Tests
int main(void) {
    // Create empty hashtable
    hashtable_t *hashtable = hashtable_new(100);
    assert(hashtable != NULL);

    // Add a key
    char *key = "Pickle";
    int item = 5;
    assert(hashtable_insert(hashtable, key, &item) == true);

    // Add key again
    assert(hashtable_insert(hashtable, key, &item) == false);

    // Test NULL parameter insert
    assert(hashtable_insert(NULL, NULL, NULL) == false);

    // Look the key up
    int *founditem = hashtable_find(hashtable, key);
    assert(*founditem = item);

    // Look up a key that is not in the hashtable
    char *fakekey = "Pickle2";
    assert(hashtable_find(hashtable, fakekey) == NULL);

    // Test NULL find
    assert(hashtable_find(NULL, fakekey) == NULL);

    // Test hashtable printing
    printf("Testing hashtable printing\n");
    hashtable_print(hashtable, stdout, printint);

    // NULL printing
    hashtable_print(NULL, stdout, NULL);

    // Test iteration
    hashtable_iterate(hashtable, NULL, iterateprint);

    // Delete hashtable
    hashtable_delete(hashtable, NULL);
    // Check for memory leaks to make sure this was successful

    printf("Hashtable Tests Successful\n");
    return 0;
}
