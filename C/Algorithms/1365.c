#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Little hashmap. {int -> int} 
 *
 * Supports only basic ops (get, set)
 * No error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    int size, length;
    unsigned (*hashfunc)(void *k);
    struct bucket {
        struct bucket *next;
        int key;
        int value;
    } **buckets;
};

// Basic hash.
unsigned hf(void* key){
    return (unsigned long)key >> 2;
}

// Base size on prime (I remember somewhere this is a good idea,
// need to find that source.)
int get_next_prime(int size){
    // return next prime after size to use as table size.
    unsigned i = 0; 
    static int PRIMES[] = {
        11, 19, 31, 43, 61, 101, 	
        137, 167, 211, 263, 313,
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
    t = (struct tablet *)malloc(
            sizeof(*t) + psize * sizeof(t->buckets[0])
            );
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
int tablet_get(struct tablet* t, int key){
    
    struct bucket *p;
    unsigned i = (*t->hashfunc)((void *)&key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // we *know* value >= 0 since they're counts, in general, 
    // this isn't good.
    return p ? p->value : -1;
}

// set key value in table.
void tablet_set(struct tablet* t, int key, int value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)((void *)&key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // Key value pair isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = (struct bucket *)malloc(sizeof(struct bucket));
        p->value = value;
        p->key = key;
        // make new binding point to old beginning
        p->next = t->buckets[i];
        t->buckets[i] = p;
        t->length++;
    }
    p->value = value;
}

// Compare function for qsort.
int cmp(const void* x, const void* y){
    int a = *(const int *)x;
    int b = *(const int *)y;

    // thanks cppreference.
    return (a > b) - (b > a);
}


/**
 * Note: Returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    // copy numbers over and sort.
    memcpy(res, nums, sizeof(int) * numsSize);    
    qsort(res, numsSize, sizeof(int), cmp);
   
    // create counts for elements in res.
    unsigned seen = 0;
    struct tablet *t = tablet_new(numsSize);
    for(unsigned i = 0; i < numsSize; i++){
       // != -1 means we have a value for key.
       if (tablet_get(t, res[i]) != -1)
          seen += 1;
       else {
          tablet_set(t, res[i], seen);
          seen += 1;
       }
    }
    // populate res with results 
    for (unsigned i = 0; i < numsSize;  i++){
        res[i] = tablet_get(t, nums[i]);
    }
    // Free table and return.
    free(t);
    *returnSize = numsSize;
    return res;
}

int main(int argc, char **argv){
    int a[] = {5, 0, 10, 0, 10, 6};
    int rs = 0;
    int *counts = smallerNumbersThanCurrent(a, 6, &rs);

    for(unsigned i = 0; i < 6; i++){
        printf("%d ", counts[i]);
    }
    puts("");

    return 0;
}
