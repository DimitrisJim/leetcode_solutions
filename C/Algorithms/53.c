int maxSubArray(int *nums, int numsSize) {
  int maximum = nums[0], prev = 0;
  for (int i = 0; i < numsSize; i++) {
    int n = *(nums + i);
    int k = n + prev;
    prev = n > k ? n : k;
    maximum = prev > maximum ? prev : maximum;
  }
  return maximum;
}