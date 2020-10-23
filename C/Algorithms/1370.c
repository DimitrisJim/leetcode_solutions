#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Little map. {char -> int}
 *
 * Supports (get, set, has, keys)
 * No error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    int size, length;
    unsigned (*hashfunc)(char k);
    struct bucket {
        struct bucket *next;
        char key;
        int value;
    } **buckets;
};

// Basic hash.
unsigned hf(char key){
    unsigned x = key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

// Create table. Size used is smallest prime that is
// larger than size supplied.
struct tablet* tablet_new(int size){
    struct tablet *t;
    int psize = 521;
    t = malloc(sizeof(*t) + psize * sizeof(t->buckets[0]));

    // Assign values.
    t->size = psize;
    t->hashfunc = hf;
    t->length = 0;
    t->buckets = (struct bucket**)(t + 1);
    // init buckets.
    for (unsigned i = 0; i < psize; i++)
        t->buckets[i] = NULL;

    return t;
}

// Free table memory.
void tablet_free(struct tablet *tablet){
    // If we have elements, go through and free them.
    if((tablet)->length > 0){
        struct bucket *p, *q;
        for(int i = 0; i < (tablet)->size; i++){
            for(p = (tablet)->buckets[i]; p; p = q){
                q = p->next;
                free(p);
            }
        }
    }
    // If not, just free the table.
    free(tablet);
}

// Get value with key `key`
int tablet_get(struct tablet* t, char key){

    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // we *know* value >= 0 since they're counts, in general,
    // this isn't good.
    return p ? p->value : -1;
}

// Check if table has specific key.
// Returns 1 if true, 0 if false.
int tablet_has(struct tablet* t, char key){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        // Return true.
        if (key == p->key)
            return 1;
    }
    // Return false.
    return 0;
}

// Set key-value pair in table.
void tablet_set(struct tablet* t, char key, int value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // Key value pair isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = malloc(sizeof(struct bucket));
        p->value = value;
        p->key = key;
        // make new binding point to old beginning
        p->next = t->buckets[i];
        t->buckets[i] = p;
        t->length++;
    }
    // Update value.
    p->value = value;
}

// Delete from the table the key. 1 success, -1 failure.
int tablet_del(struct tablet *t, char key){
    if((t)->length > 0){
        struct bucket *p, *q;
        unsigned i = (*t->hashfunc)(key) % t->size;
        for(p = t->buckets[i]; p; p = p->next){
            if(key == p->key){
                // Re-align nodes.
                q = p;
                p = p->next;
                free(q);
                t->length--;
                t->buckets[i] = p;
                return 1;
            }
        }
    }
    return -1;
}

// Keys must be free'd by caller, size of keys is
// returned via keys_size.
char *tablet_keys(struct tablet* t, int *keys_size){
    // Iterate through nodes and find key:
    char *keys = malloc(t->length);
    struct bucket *p, *q;
    for(int i = 0, j=0; i < (t)->size; i++){
        for(p = (t)->buckets[i]; p; p = q){
            // Add to keys and advance
            keys[j] = p->key;
            j++;
            q = p->next;
        }
    }
    // Set keys_size.
    *keys_size = t->length;
    return keys;
}

//---------- End of little table implementation --------------//

// Sorting functions. One reverse one normal.
int ascending(const void *a, const void *b){
    // ascending
    return *(char *)a - *(char *)b;
}

int descending(const void *a, const void *b){
    return -ascending(a, b);
}


char * sortString(char *s){
    int slen = strlen(s);
    struct tablet *t = tablet_new(slen+1);
    // Create a table of counts. (NOTE: slen, not slen + 1.)
    for(int i = 0; i < slen; i++){
        char k = s[i];
        // if true, k: val => k: val+1
        if (tablet_has(t, k)){
            int val = tablet_get(t, k);
            tablet_set(t, k, val + 1);
        // set initial value of 1.
        } else {
            tablet_set(t, k, 1);
        }
    }
    int keys_size;
    // NOTE: Free both at end.
    char *reversed, *sorted = tablet_keys(t, &keys_size);
    // We can bail early here if keys_size == 1 or slen.
    if (keys_size == 1){
        free(sorted);
        tablet_free(t);
        return s;
    }
    if (keys_size == slen){
        // Sort s and return it.
        char *chars = malloc(slen+1);
        memcpy(chars, s, slen+1);
        qsort(chars, slen, sizeof(char), ascending);
        // Note caller frees chars.
        free(sorted);
        tablet_free(t);
        return chars;
    }
    // Sort first array.
    qsort(sorted, keys_size, sizeof(char), ascending);
    // Create and sort second array.
    reversed = malloc(keys_size);
    memcpy(reversed, sorted, keys_size);
    qsort(reversed, keys_size, sizeof(char), descending);

    // Go through sorted/reversed and fill up res.
    char *res = malloc(slen+1);
    res[slen] = '\0';
    unsigned toggle = 0, pending = 1, j = 0;
    while (pending != 0){
        for(int i = 0; i < keys_size; i++){
            // choose value from correct array.
            char key = toggle ? reversed[i]: sorted[i];
            if (tablet_has(t, key)) {
                int value = tablet_get(t, key);
                // case 1: table has key with only one occurence.
                // => Remove key and break if table length is 1.
                if (value == 1){
                    tablet_del(t, key);
                    if (t->length == 1)
                        pending ^= 1;
                // case 2: table has key with 1+ occurences.
                // => Decrement count.
                } else {
                    tablet_set(t, key, value-1);
                }
                // Add to res.
                res[j] = key;
                j++;
            }
        }
        toggle ^= 1;
    }
    // Handle the case of 1 remaining character.
    if (t->length == 1){
        int ks;
        char *keys = tablet_keys(t, &ks);
        if (ks != 1){
            // Error.
            return "";
        }
        char key = keys[0];
        free(keys);
        // key val will be slen - j
        for(int i = j; i < slen; i++)
           res[i] = key;
    }

    free(sorted);
    free(reversed);
    tablet_free(t);
    return res;
}

int main(void){
    char *c = "irqhaprcwbsdctibwfzagnsfetisgykicuvjqnigekmjpamcyybrwolfwmgltqnjxypqamutxojpczwfzlfjbqsqflmihmrbhoylvkxjnxkwmxxglhcthtdnccnfadizvihzizjbbjavzimuatpyjykwjuhnkdublgzqwgwgmsnbelokdonhrknacizvyqycuroqptkzgkyjiczawauscwsmcvbkdvsrrusknrleqvkwtrkxoqycugpupisyslsqldknkztbhkfcfufmtaynrdquudpxrsmwq";
    char *res = sortString(c);

    puts(res); 
    free(res);
    return 0;
}
