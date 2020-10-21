#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

/* Little set {char *} 
 *
 * Supports only basic ops (get, set, intersection)
 * No thorough error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    unsigned size, length;
    unsigned long (*hashfunc)(const char *k);
    // Separate chaining (with a linked list).
    struct bucket {
        struct bucket *next;
        const char* value;
    } **buckets;
};

// polynomial rolling hash function, thanks:
// https://cp-algorithms.com/string/string-hashing.html
unsigned long hf(const char* key){
    const int p = 31;
    const int m = 1e9 + 9;
    int len = strlen(key);
    long long hash_value = 0;
    long long p_pow = 1;
    for(int i = 0; i < len; i++) {
        hash_value = (hash_value + (key[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
    return (unsigned long)key >> 2;
}

// Base size on prime (I remember somewhere this is a good idea,
// need to find that source.)
int get_next_prime(int size){
    // return next prime after size to use as table size.
    unsigned i = 0; 
    static int PRIMES[] = {
        7, 17, 29, 37, 47, 59,
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
                free((void *)p->value);
                free(p);
            }
        }
    }
    // If not, just free the table.
    free(tablet);
}

// get value with key `key`
int tablet_has(struct tablet* t, const char* val){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(val) % t->size; 
    for(p = t->buckets[i]; p; p = p->next){
        if(strcmp(val, p->value) == 0)
            return 1;
    }
    return 0;
}

// set key value in table.
void * tablet_set(struct tablet* t, const char* value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(value) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(strcmp(value, p->value) == 0)
            break;
    }
    // Key value pair isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = malloc(sizeof(struct bucket));
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
    // free in uniqueMorseRepresentations. Meh.
    const char *old_value = p->value;
    p->value = value;
    free((void *)old_value);
    return t;
}

// Tailored for this problem where we know their intersection consists 
// of a single element, we just return that.
const char* single_intersection(struct tablet *s, struct tablet *s2){
    // Go through elements of s and on first false return from 
    // s2.has, return.
    // If we have elements, go through and free them.
    if((s)->length > 0){
        struct bucket *p, *q;
        for(int i = 0; i < (s)->size; i++){
            for(p = (s)->buckets[i]; p; p = q){
                if(!tablet_has(s2, p->value)){
                    return p->value;
                }
                q = p->next;
            }
        }
    }
    return (const char *)"";
}

char * destCity(char ***paths, int pathsSize, int* pathsColSize){
    struct tablet *sources = tablet_new(pathsSize);
    struct tablet *dests = tablet_new(pathsSize);
    for(int i = 0; i < pathsSize; i++){
        char *source = malloc(strlen(paths[i][0]) + 1);
        strcpy(source, paths[i][0]);
        char *dest = malloc(strlen(paths[i][1]) + 1);
        strcpy(dest, paths[i][1]);
        tablet_set(sources, source);
        tablet_set(dests, dest);
    }
    char *res = single_intersection(dests, sources);
    free(sources);
    free(dests);
    // should be free'd but meh
    return res;
}
