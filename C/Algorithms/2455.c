int averageValue(int* nums, int numsSize){
    int sum = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        int value = nums[i];
        if ((value & 1) == 0 && (value % 3) == 0) {
            sum += value;
            count++;
        }
    }
    return count == 0 ? count : (int)sum/count;
}