# CS50 Lab 3 - Counters
## Graeme Gengras, April 2018

### Counters
A `counter set` is a set of `counters`, each distinguished by an integer `key`. Each `key` can only occur once in the `set`, and when an existing `key` is added to the `set` it increments the `counter` associated with that `key`. The current `counter` value can be retrieved by asking for the relevant `key`.

### Usage

The `counters` module, defined in `counters.h` and implemented in `counters.c`, implements an `int` `counter` and exports the following functions through `counters.h`:

```c
/* Create a new (empty) counter structure; return NULL if error. */
counters_t *counters_new(void);

/* Increment the counter indicated by key; key must be >= 0.
 * If the key does not yet exist, create a counter for it and initialize to 1.
 * Ignore if ctrs is NULL or key is negative.
 */
void counters_add(counters_t *ctrs, const int key);

/* Return current value of counter associated with the given key;
 * return 0 if ctrs is NULL or if key is not found.
 */
int counters_get(counters_t *ctrs, const int key);

/* Set the current value of counter associated with the given key;
 * If the key does not yet exist, create a counter for it and initialize to
 * the given value. Ignore if ctrs is NULL, if key < 0, or count < 0.
 */
void counters_set(counters_t *ctrs, const int key, int count);

/* Print all counters; provide the output file.
 * Ignore if NULL fp. Print (null) if NULL ctrs.
 */
void counters_print(counters_t *ctrs, FILE *fp);

/* Iterate over all counters in the set (in undefined order):
 * call itemfunc for each item, with (arg, key, count).
 * If ctrs==NULL or itemfunc==NULL, do nothing.
 */
void counters_iterate(counters_t *ctrs, void *arg,
                      void (*itemfunc)(void *arg, const int key, int count));

/* Delete the whole counters. ignore NULL ctrs. */
void counters_delete(counters_t *ctrs);
```

### Implementation

We implement the `counter set` as a linked list where each node contains a key and an item.  The `counter set` itself is a struct containing a pointer to the head of the list; the head pointer is NULL when the bag is empty.

Each node in the list is a `struct counter`, a type defined internally to the module. Each counter includes a copy of the `int key`, a copy of the `int counter` and a pointer to the next counter in the counter set.

To insert a new key counter pair in the counter set we create a new counter and insert it at the head of the list.

To extract an item from the set we remove the head of the list and return its item, deleting its counter. If the list is empty the return is NULL.

The `counters_print` method calls the `itemprint` function on each counter in the counter set with a minimal amount of formatting.

The `counters_iterate` method calls the `itemfunc` function on each counter in the counter set.

The `counters_delete` method calls the `itemdelete` function on each counter in the counter set, freeing counters as it proceeds. It concludes by freeing the counter set itself.

### Assumptions

The `key` must be greater than zero, `count` must always be greater than zero.

### Compilation

To compile, simply `make` in the counters directory, or `make` in the parent directory to compile the entire library (which also includes `set` and `hashtable`).

To test, simply `make test` in the counters directory.
See [TESTING.md](TESTING.md) for details of testing and an example test run.
