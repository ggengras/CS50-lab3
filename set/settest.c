#include <assert.h>
#include <stdbool.h>
#include "set.h"

// Item print functions

// Item delete functions

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

    // Test printing

    // Test deletion

    printf("Set Tests Successful\n");
    return 0;
}
