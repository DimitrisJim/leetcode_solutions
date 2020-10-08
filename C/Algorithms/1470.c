#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    if (numsSize == 2) {
        // trivial case, return immediately.
        *returnSize = numsSize;
        return nums;
    }
    // allocate array.
    int *arr = (int *)malloc(numsSize * sizeof(int));

    // simple & readable; loop [0 -> numsSize]
    // if even, grab from [0-n) part of nums
    // if odd, grab from [n-numsSize) part of nums
    for(unsigned i = 0, j = 0; i < numsSize; i++){
        if (i % 2){
            arr[i] = nums[n];
            n += 1;
        } else {
            arr[i] = nums[j];
            j += 1;
        }
    }
    
    *returnSize = numsSize;
    return arr;
}
