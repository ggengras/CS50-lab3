# CS50 Lab 3 - Set
## Graeme Gengras, April 2018

### Set
 A `set` is an unordered collection of (`key`, `item`) pairs. Any given `key` can only occur once in the `set`. The `set` starts empty. The caller can retrieve `items` by asking for their `key`, but cannot remove or update pairs. `Items` are distinguished by their `keys`. `Items` can be any type, `keys` must be `char*`.

### Usage

The `set` module, defined in `set.h` and implemented in `set.c`, implements a `set` of `void*` and exports the following functions through `set.h`:

```c
/* Create a new (empty) set; return NULL if error. */
set_t *set_new(void);

/* Insert item, identified by a key (string), into the given set.
 * The key string is copied for use by the set.
 * Return false if key exists, any parameter is NULL, or error;
 * return true if new item was inserted.
 */
bool set_insert(set_t *set, const char *key, void *item);

/* Return the item associated with the given key;
 * return NULL if set is NULL, key is NULL, or key is not found.
 */
void *set_find(set_t *set, const char *key);

/* Print the whole set; provide the output file and func to print each item.
 * Ignore if NULL fp. Print (null) if NULL set.
 * Print a set with no items if NULL itemprint.
*/
void set_print(set_t *set, FILE *fp,
               void (*itemprint)(FILE *fp, const char *key, void *item) );

/* Iterate over all items in the set, in undefined order.
 * Call the given function on each item, with (arg, key, item).
 * If set==NULL or itemfunc==NULL, do nothing.
 */
void set_iterate(set_t *set, void *arg,
                 void (*itemfunc)(void *arg, const char *key, void *item) );

/* Delete the whole set; ignore NULL set.
 * Provide a function that will delete each item (may be NULL).
 */
void set_delete(set_t *set, void (*itemdelete)(void *item) );
```

### Implementation

We implement the `set` as a linked list where each node contains a key and an item.  The `set` itself is a struct containing a pointer to the head of the list; the head pointer is NULL when the bag is empty.

Each node in the list is a `struct setpair`, a type defined internally to the module. Each setpair includes a pointer to the `void *item`, a copy of the `char *key` and a pointer to the next setpair in the set.

To insert a new key item pair in the set we create a new setpair to hold the `item`, and insert it at the head of the list.

To extract an item from the set we remove the head of the list and return its item, deleting its setpair. If the list is empty the return is NULL.

The `set_print` method calls the `itemprint` function on each pair in the set with a minimal amount of formatting.

The `set_iterate` method calls the `itemfunc` function on each pair in the set.

The `set_delete` method calls the `itemdelete` function on each pair in the set, freeing pairs as it proceeds. It concludes by freeing the set itself.

### Assumptions

The `item` and `key` inserted cannot be NULL.

### Compilation

To compile, simply `make` in the set directory, or `make` in set's parent directory to compile the entire library (which also includes `counter` and `hashtable`).

To test, simply `make test` in the set directory.
See [TESTING.md](TESTING.md) for details of testing and an example test run.
