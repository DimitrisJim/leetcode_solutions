#define COUNT_MAX 101  // Max value in nums + 1.

int countKDifference(int* nums, int numsSize, int k){
    // normally no, due to constraints ok for this case.
    int counter[COUNT_MAX] = {0};
    
    for (int i = 0; i < numsSize; i++)
        counter[nums[i]]++;
    
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int a = num - k, b = num + k;
        if (a > 0 && a < COUNT_MAX && counter[a])
            count += counter[a];
        if (b < COUNT_MAX && counter[b])
            count += counter[b];
        counter[num]--;        
    }
    return count;
}