#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "set.h"

// Item print functions
void printint(FILE *fp, const char *key, void *item) {
    int *valuep = item;
    fprintf(fp, "%s:%d", key, *valuep);
}

// Item delete functions
void intdelete(void *item) {
    int *valued = item;
    free(&valued);
}

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
    printf("Test printing\n");
    set_print(set, stdout, printint);

    // Test deletion
    set_delete(set, intdelete);
    free(set);
    printf("\nSet Tests Successful\n");
    return 0;
}
