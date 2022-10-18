int cmpi_abs(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;
    
    a = a < 0 ? -a: a;
    b = b < 0 ? -b: b;
    
    return (a > b) - (a < b);
}

int findMaxK(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(*nums), cmpi_abs);
    for (int i = numsSize-1; i > 0; i--) {
        int a = nums[i], b = nums[i-1];
        if (a + b == 0)
            return a > b ? a: b;
    }
    return -1;
}