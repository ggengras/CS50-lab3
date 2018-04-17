/*
* set.c   Graeme Gengras, April 2018
*
*
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

/**************** local types ******************/
typedef struct setpair {
    void *item;
    char *key;
    struct setpair *next;
} setpair_t;

/**************** global types *****************/
typedef struct set {
    struct setpair *head;
} set_t;

/**************** local functions **************/
static setpair_t *setpair_new(char *key, void *item) {
    setpair_t *setpair = malloc(sizeof(setpair_t));

    if (setpair == NULL) {
        return NULL; // Memory not properly allocated
    } else {
        setpair->key = key;
        setpair->item = item;
        return setpair;
    }
}

/**************** something **************/
set_t *set_new(void) {
    set_t *set = malloc(sizeof(set_t));

    if (set == NULL) {
        return NULL; // Memory was not properly allocated
    } else {
        set->head = NULL; // Set is initialized empty
        return set;
    }
}

bool set_insert(set_t *set, const char *key, void *item) {
    if (set != NULL && item != NULL && key != NULL) {
        // Need to copy key to not discard const qualifier
        char *keycpy = malloc(strlen(key) + 1);
        strcpy(keycpy, key);

        setpair_t *new = setpair_new(keycpy, item); // New key/value pair

        // Make sure key doesn't already exist
        if (set_find(set, keycpy) == NULL) {
            // Add new items to the head
            new->next = set->head;
            set->head = new;
            return true;
        }
    } else {
        // Returns false if set, key, or item is NULL
        // or if key already exists
        return false;
    }
}

void *set_find(set_t *set, const char *key) {

}

void set_print(set_t *set, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item) ) {


}


void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) ) {

}

void set_delete(set_t *set, void (*itemdelete)(void *item)) {

}
