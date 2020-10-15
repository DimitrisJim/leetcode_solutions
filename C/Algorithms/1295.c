int findNumbers(int* nums, int numsSize){
    int sum = 0, j;
    for(int i=0; i < numsSize; i++){
        j = nums[i];
        if (
            ((9 < j) && (j < 100)) || 
            ((999 < j) && (j < 10000)) || 
            (j == 100000)
        )
            sum++;
    }
    return sum;
}

// Pointer arithmetic, leads to better exec speed.
int findNumbers2(int* nums, int numsSize){
    int sum = 0;
    while(numsSize){
        if (
            ((9 < *nums) && (*nums < 100)) ||
            ((999 < *nums) && (*nums < 10000)) ||
            (*nums == 100000)
        )
            sum++;
        nums++;
        numsSize--;
    }
    return sum;
}
