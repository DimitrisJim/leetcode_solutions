#include <stdlib.h>

// compare func to pass to qsort.
int compare(const void* a, const void* b){
    int x = *(const int *)a;
    int y = *(const int *)b;

    // thanks cppreference.
    return (x & 1) - (y & 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    // sort the nums.
    qsort(A, ASize, sizeof(int), compare);
    *returnSize = ASize; 
    return A;
}
