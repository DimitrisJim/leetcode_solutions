int cmpi(const void *x, const void *y) {
    int a = *(const int *)x;
    int b = *(const int *)y;

    return (a > b) - (a < b);
}

int minimumSum(int num){
    int nums[4] = {0, 0, 0, 0};
    int d = 1000, i = 0;
    while (d) {
        nums[i++] = num / d;
        num %= d;
        d /= 10;
    }

    // Sort nums to bring to least order.
    qsort(nums, 4, sizeof(*nums), cmpi);
    
    return (nums[0]*10 + nums[2]) + (nums[1] * 10 + nums[3]);
}