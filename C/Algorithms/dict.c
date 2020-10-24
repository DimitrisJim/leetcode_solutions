/**
 * Created by jim.
 *
*/
#include <limits.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

/**
 * Table structure:
 *
 * @member size Number of available buckets.
 * @member cmp The comparison function used for this table.
 * @member h The hash function used for this table.
 * @member timestamp A timestamp of the last insertion/deletion.
 * @member length The number of bindings (i.e # of key-value pairs.)
 * @member buckets The table which we use as a hash table.
 */
typedef struct table{
  int size;
  int (*cmp)(const void *x, const void *y);
  unsigned (*hash_func)(const void *k);
  unsigned timestamp;
  int length;
  /**
   * A linked list of key value pairs that hash to the same value
   * inside the hash table.
   *
   * @member link A link to the next binding that hashes to same bucket.
   * @member key The key stored.
   * @member value The value stored.
   */
  struct binding {
    struct binding *link;
    const void *key;
    void *value;
  } **buckets;
} tablet;

static int cmpatom(const void *x, const void *y){
    return x != y;
}
static unsigned hashatom(const void *key){
    return (unsigned long)key >> 2;
}

tablet * Table_new(int hint, int (*cmp)(const void *x, const void *y), unsigned (*hash)(const void *key)){
    // TODO: Add more primes.
    static int PRIMES[] = {
        509, 509, 1021, 2053, 4093, 8191, 16381, 32771, 65521, INT_MAX
    };
    tablet *table;
    int i;

    assert(hint >= 0);
    // Find a suitable value for the size.
    for(i=1; PRIMES[i] < hint; i++);

    table = malloc(sizeof(*table) + PRIMES[i-1] * sizeof(table->buckets[0]));
    // Assign fields to table.
    table->size = PRIMES[i-1];
    table->cmp = cmp ? cmp : cmpatom;
    table->hash_func = hash ? hash : hashatom;
    table->buckets = (struct binding **)(table + 1);
    
    for(i = 0; i < table->size; i++)
        table->buckets[i] = NULL;
    table->timestamp = table->length = 0;
    return table;
}

void Table_free(tablet **table){
    assert(*table != NULL);
    assert(table != NULL);

    // If we have elements, go through and free them.
    if((*table)->length > 0){
        struct binding *p, *q;
        for(int i = 0; i < (*table)->size; i++){
            for(p = (*table)->buckets[i]; p; p = q){
                q = p->link;
                free(p);
            }
        }
    }
    // Just free the table.
    free(*table);
}

int Table_length(tablet *table){
    assert(table != NULL);
    return table->length;
}

void * Table_put(tablet *table, const void *key, void *value){
    assert(table != NULL);
    assert(key != NULL);

    struct binding *p;
    unsigned i = (*table->hash_func)(key) % table->size;
    for(p = table->buckets[i]; p; p = p->link){
        if((*table->cmp)(key, p->key) == 0)
            break;
    }
    // Key value pair isn't present in table.
    void *tmp;
    // add it and adjust values.
    if (p == NULL){
        p = malloc(sizeof *p);
        p->value = value;
        p->key = key;
        // make new binding point to old beginning
        p->link = table->buckets[i];
        table->buckets[i] = p;
        table->length++;
        tmp = NULL;
    } else  // Keep old value around.
        tmp = p->value;
    p->value = value;
    table->timestamp++;

    return tmp;
}

void * Table_get(tablet *table, const void *key){
    assert(table != NULL);
    assert(key != NULL);

    struct binding *p;
    unsigned i = (*table->hash_func)(key) % table->size;
    for(p = table->buckets[i]; p; p = p->link){
        if((*table->cmp)(key, p->key) == 0)
            break;
    }
    return p ? p->value : NULL;
}

void * Table_remove(tablet *table, const void *key){
    assert(table);
    assert(key);

    struct binding **pp;

    unsigned i = (*table->hash_func)(key) % table->size;
    for(pp = &table->buckets[i]; *pp; pp = &(*pp)->link){
        if((*table->cmp)(key, (*pp)->key) == 0){
            // Found binding; remove from linked list and
            // return its value.
            struct binding *p = *pp;
            void *tmp = (*pp)->value;
            *pp = p->link;
            free(p);
            table->length--;
            table->timestamp++;

            return tmp;
        }
    }
    // Nothing was found; return NULL.
    return NULL;
}

void ** Table_toArray(tablet *table, void *end){
    assert(table != NULL);

    void **array;
    int j = 0;
    struct binding *p;

    // Allocate size for the array and then go through table and
    // populate the array.
    array = malloc((2 * table->length + 1) * sizeof(*array));
    for(int i = 0; i < table->size; i++){
        for (p = table->buckets[i]; p; p = p->link){
            // drop const qualifier.
            array[j++] = (void *)p->key;
            array[j++] = p->value;
        }
    }
    array[j] = end;
    // Users must free.
    return array;
}
