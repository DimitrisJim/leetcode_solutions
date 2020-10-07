#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool* arr = (bool *)malloc(candiesSize * sizeof(bool));
    int max = INT_MIN;
    
    // Find max among candies.
    for(unsigned i=0; i < candiesSize; i++){
        if (candies[i] >= max) {
            max = candies[i];
        }
    }
    
    for(unsigned i=0; i < candiesSize; i++){
        if ((candies[i] + extraCandies) >= max){
            arr[i] = true;
        } else {
            arr[i] = false;
        }
    }
    *returnSize = candiesSize;
    return arr;
}

int main(int argc, char **argv){
    int candies[5] = {1, 2, 3, 2, 1};
    int resSize = 0;
    bool *res = kidsWithCandies(candies, 5, 2, &resSize);
    for(unsigned i = 0; i < 5; i++){
        printf("%d ", res[i]);
    }
    return 0;
}
