#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/* Little hashmap. {int -> int} 
 *
 * Supports only basic ops (get, set)
 * No error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    unsigned size, length;
    unsigned (*hashfunc)(int k);
    // Separate chaining (with a linked list).
    struct bucket {
        struct bucket *next;
        int value;
    } **buckets;
};

// Basic hash.
unsigned hf(int key){
    return (unsigned long)key >> 2;
}

// Base size on prime (I remember somewhere this is a good idea,
// need to find that source.)
int get_next_prime(int size){
    // return next prime after size to use as table size.
    unsigned i = 0; 
    static int PRIMES[] = {
        7, 17, 29, 43, 53,
        61, 101, 137, 167, 211, 263, 313,
        367, 401, 449, 	503, INT_MAX 	
    };

    for(;; i++){
        if (size <= PRIMES[i])
            break;
    } 
    // return first prime that is > size.
    return PRIMES[i];
}

// Create table.
struct tablet* tablet_new(int size){
    struct tablet *t;
    int psize = get_next_prime(size);
    if (psize < size){
        // Problem here. Bail.
        return NULL;
    }
    t = (struct tablet *)malloc(
            sizeof(*t) + psize * sizeof(t->buckets[0])
            );
    if (t == NULL){
        return NULL;
    }
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

// delete table.
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

// get value with key `key`
int tablet_has(struct tablet* t, int val){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(val) % t->size; 
    for(p = t->buckets[i]; p; p = p->next){
        if(val == p->value)
            return 1;
    }
    return 0;
}

// set key value in table.
void * tablet_set(struct tablet* t, int value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(value) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(value == p->value)
            break;
    }
    // Key isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = (struct bucket *)malloc(sizeof(struct bucket));
        if (p == NULL){
            return NULL;
        }
        p->value = value;
        // make new binding point to old beginning
        p->next = t->buckets[i];
        t->buckets[i] = p;
        t->length++;
        return t;
    }
    return t;
}

int numJewelsInStones(char * J, char * S){
    struct tablet* s = tablet_new(50);
    int l = strlen(J);
    for(int i = 0; i < l; i++){
        tablet_set(s, (int)J[i]);
    }
    int l2 = strlen(S);
    int count = 0;
    for(int i = 0; i < l2; i++){
        if(tablet_has(s, (int)S[i]) == 1){
            count++;
        }
    }
    return count;
}
