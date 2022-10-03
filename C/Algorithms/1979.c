int findGCD(int* nums, int numsSize){
    int min = 1001, max = 0;
    for (int i = 0; i < numsSize; i++){
        int num = nums[i];
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    
    while (min != 0){
        int temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}