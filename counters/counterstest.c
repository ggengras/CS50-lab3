/*
* counters.c  Graeme Gengras, April 2018
*
* Simple testing file for the counters module.  See function
* details in counters.h.  Each function is tested
* with normal and NULL parameters
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "counters.h"

// Iterate function
void iterateprint(void *arg, const int key, int count) {
    printf("%d:%d\n", key, count);
}

int main(void) {
    // Create empty counter set
    counters_t *counterset = counters_new();
    assert(counterset != NULL);

    // Add a key
    int key = 10001;
    counters_add(counterset, key);
    // Make sure it's there
    assert(counters_get(counterset, key) == 1);

    // Try to get a non-existent key
    assert(counters_get(counterset, 50005) == 0);

    // Add a negative key (should do nothing)
    counters_add(counterset, -10);

    // Add key to null counterset (should do nothing)
    counters_add(NULL, key);

    // Set count with new key
    int keytwo = 20002;
    int count = 10;
    counters_set(counterset, keytwo, count);
    assert(counters_get(counterset, 20002) == 10);

    // Set count with negative key (should do nothing)
    counters_set(counterset, -10, count);

    // Set negative count (should do nothing)
    counters_set(counterset, keytwo, -10);

    // Set count for NULL counter set (should do nothing)
    counters_set(counterset, keytwo, count);

    // Test printing
    printf("Testing counter set printing\n");
    counters_print(counterset, stdout);

    // Test NULL printing
    printf("Testing NULL counter set printing\n");
    counters_print(NULL, stdout);

    // Test iteration
    printf("Testing iteration (with printing)\n");
    counters_iterate(counterset, NULL, iterateprint);

    // Test deletion
    counters_delete(counterset);
    // Check for memory leaks to make sure this was successful

    return 0;
}
