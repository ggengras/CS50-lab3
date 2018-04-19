/*
* counterstest.c  Graeme Gengras, April 2018
*
*
*
*
*
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "counters.h"

int main(void) {
    // Create empty counter set
    counters_t *counterset = counters_new();
    assert(counterset != NULL);

    // Add a key
    int key = 10001;
    counters_add(counterset, key);
    assert(counters_get(counterset, key) == 1);

    // Try to get a non-existent key
    assert(counters_get(counterset, 50005) == 0);

    // Test counter set with new key
    int keytwo = 20002;
    int count = 10;
    counters_set(counterset, keytwo, count);
    assert(counters_get(counterset, 20002) == 10);

    // Test printing
    printf("Testing counter set printing\n");
    counters_print(counterset, stdout);

    // Test deletion
    counters_delete(counterset);
    // Check for memory leaks to make sure this was successful






    return 0;
}
