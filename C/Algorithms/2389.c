#include "math.h"

int cmpint(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;
    
    return (a > b) - (a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    qsort(nums, numsSize, sizeof(*nums), cmpint);
    
    int acc = 0;
    for(int i = 0; i < numsSize; i++) {
        nums[i] += acc;
        acc = nums[i];
    }
    
    int *result = malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int needle = queries[i], index = 0;
        // Binary Search:
        int left = 0, right = numsSize;
        while (left < right) {
            int m = (left + right) / 2;
            if (nums[m] > needle) 
                right = m;
            else 
                left = m + 1;
        }
        result[i] = right;
    }
    *returnSize = queriesSize;
    return result;
}