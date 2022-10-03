int cmpint(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;
    
    return (a > b) - (a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums, numsSize, sizeof(*nums), cmpint);
    
    int size = 2, idx = 0;
    int *result = malloc(size * sizeof(*result));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            if (idx == size) {
                size *= 2;
                result = realloc(result, size * sizeof(*result));
            }
            result[idx++] = i;
        }
    }
    *returnSize = idx;
    return result;
}