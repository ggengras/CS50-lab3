/*
* settest.c  Graeme Gengras, April 2018
*
*
*
*
*
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "hashtable.h"

int main(void) {
    // Create empty hashtable
    hashtable_t *hashtable = hashtable_new(100);
    assert(hashtable != NULL);

    // Add a key
    char *key = "Pickle";
    int item = 5;
    assert(hashtable_insert(hashtable, key, &item) == true);

    // Look the key up
    int *founditem = hashtable_find(hashtable, key);
    assert(*founditem = item);

    // Look up a key that is not in the hashtable
    char *fakekey = "Pickle2";
    assert(hashtable_find(hashtable, fakekey) == NULL);

    // Test hashtable printing
    printf("Test printing\n");
    hashtable_print(hashtable, stdout, NULL);

    // Delete hashtable
    hashtable_delete(hashtable, NULL);

    printf("Hashtable Tests Successful\n");
    return 0;
}
