#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * Note 2: Not sure why leet doesn't accept this.
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    returnSize = (int *)malloc(numsSize * sizeof(int));
    int running_sum = 0;
    for(unsigned i = 0; i < numsSize; i++){
        running_sum += nums[i];
        returnSize[i] = running_sum;
    }
    return returnSize;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *b = runningSum(a, 5, (int *)NULL);
    for(unsigned i = 0; i < 5; i++)
        printf("%d ", b[i]);
    free(b);
}
