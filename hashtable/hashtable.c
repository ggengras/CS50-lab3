/*
* hashtable.c  Graeme Gengras, April 2018
*
*
*
*
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "jhash.h"
#include "../set/set.h"

typedef struct hashtable {
    struct set *set; // A hashtable is a set
} hashtable_t;

hashtable_t *hashtable_new(const int num_slots)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));
    set_t *set = set_new();

    if (hashtable == NULL || set == NULL) {
        return NULL; // Error allocating memory
    } else {
        // Initialize contents of hashtable
        hashtable->set = set;
        return hashtable;
    }
}

bool hashtable_insert(hashtable_t *ht, const char *key, void *item)
{

}

void *hashtable_find(hashtable_t *ht, const char *key)
{

}

void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item))
{

}

void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item))
{

}

void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item))
{

}
