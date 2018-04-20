# CS50 Lab 3 - Hashtable
## Graeme Gengras, April 2018

### Hashtable
A `hashtable` is an array of slots, the size of which is determined by the modulus of the hashing function.  It stores (`key`:`item`) pairs just like a `set`, but has a much faster lookup time because the hashing function maps each key to a known slot in the list.  Hashing is done using the Jenkins Hashing function - see `jhash.[ch]` for more details.

### Usage

The `hashtable` module, defined in `hashtable.h` and implemented in `hashtable.c`, implements a `hashtable` of (`char *key`:`void *item`) pairs and exports the following functions through `hashtable.h`:

```c
/* Create a new (empty) hashtable; return NULL if error. */
hashtable_t *hashtable_new(const int num_slots);

/* Insert item, identified by key (string), into the given hashtable.
 * The key string is copied for use by the hashtable.
 * Return false if key exists in ht, any parameter is NULL, or error;
 * return true iff new item was inserted.
 */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item);

/* Return the item associated with the given key;
 * return NULL if hashtable is NULL, key is NULL, key is not found.
 */
void *hashtable_find(hashtable_t *ht, const char *key);

/* Print the whole table; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL ht.
 * Print a table with no items if NULL itemprint.
 */
void hashtable_print(hashtable_t *ht, FILE *fp,
                     void (*itemprint)(FILE *fp, const char *key, void *item));

/* Iterate over all items in the table; in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If ht==NULL or itemfunc==NULL, do nothing.
 */
void hashtable_iterate(hashtable_t *ht, void *arg,
               void (*itemfunc)(void *arg, const char *key, void *item) );

/* Delete the whole hashtable; ignore NULL ht.
 * Provide a function that will delete each item (may be NULL).
 */
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) );
```

### Implementation

We implement the `hashtable` as a an array of `set` pointers. Because each member of the array is a `set`, when the hashing function produces a collision we simply add more members to the set in the slot where the collision occurs.

See the `set` module for more information about how sets work.

To insert a new (`key`:`item`) pair in the `hashtable` we hash the `key` to determine what slot it goes in and then add the (`key`:`item`) pair to the set contained by that slot in the `hashtable`.

To extract an item from the `hashtable` we go to the correct slot and extract the item from the set contained by that slot.

The `hashtable_print` method calls the `itemprint` function on each pair in the hashtable with a minimal amount of formatting.

The `hashtable_iterate` method calls the `itemfunc` function on each pair in the hashtable.

The `hashtable_delete` method calls the `itemdelete` function on each pair in the hashtable, freeing pairs as it proceeds. It concludes by freeing the hashtable itself.

### Assumptions

The `item` and `key` inserted cannot be NULL.

The number of slots must be greater than 0.

### Compilation

To compile, simply `make` in the hashtable directory, or `make` in the parent directory to compile the entire library (which also includes `set` and `counters`).

To test, simply `make test` in the hashtable directory.
See [TESTING.md](TESTING.md) for details of testing and an example test run.
