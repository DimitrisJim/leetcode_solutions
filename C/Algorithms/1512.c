#include <stdio.h>
#include <stdlib.h>

// compare func to pass to qsort.
int compare(const void* a, const void* b){
    int x = *(const int *)a;
    int y = *(const int *)b;

    // thanks cppreference.
    return (x > y) - (y > x);
}

int sn(int n){
    return (n * (n + 1)) / 2;
}

int numIdenticalPairs(int* nums, int numsSize){
    // sort the nums.
    qsort(nums, numsSize, sizeof(int), compare);
    int num_pairs = 0;
    int num = 0;
    for(unsigned i = 1; i < numsSize; i++){
        if (nums[i] == nums[i - 1]) {
            num += 1;
        } else {
            num_pairs += sn(num);
            num = 0;
        }
    }
    return num_pairs + sn(num);
}

int main(int argc, char **argv){
    int nums[6] = {1, 2, 3, 1, 1, 3};
    printf("%d\n", numIdenticalPairs(nums, 6));
    
    return 0;
}
