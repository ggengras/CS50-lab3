#include <assert.h>
#include <stdbool.h>
#include "set.h"

int main(void) {
    // Make a new set
    set_t *set;
    set = set_new();
    assert(set != NULL); // Make sure pointer is good

    // Add a key/value pair to the set
    char *key = "key";
    int value = 5;
    assert(set_insert(set, key, &value) == true);

    printf("Set Tests Complete\n");
    return 0;
}
