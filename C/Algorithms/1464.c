int maxProduct(int* nums, int numsSize){
    // 1 <= nums[i] <= 10 ** 3
    int i = 0, max = 0, index, res=0;
    while(i < numsSize){
        // find max
        int n = *(nums + i);
        if(max < n){
            max = n;
            index = i;
        }
        i++;
    }
    res += (max - 1);
    // remove max by essentially making it equal an 
    // invalid value.
    *(nums + index) = -1;
    max = i = 0;
    while(i < numsSize){
        // find max
        int n = *(nums + i);
        if(max < n)
            max = n;
        i++;
    }
    res *= (max - 1);
    return res;
}
