void nextPermutation(int *nums, int numsSize) {
  numsSize--;
  int i = numsSize, j = numsSize;
  // pos of shortest non-decreasing seq.
  while (i > 0) {
    if (nums[i - 1] < nums[i])
      break;
    i--;
  }
  int k = 0;
  if (i > 0) {
    // find smallest value > nums[i-1]
    while (j >= i) {
      if (nums[j] > nums[i - 1])
        break;
      j--;
    }
    // Switch i-1 with j
    int tmp = nums[i - 1];
    nums[i - 1] = nums[j];
    nums[j] = tmp;
    // reverse *after* i
    k = i;
  }
  // reverse rest of nums
  for (int i = k, j = numsSize; i < j; i++, j--) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
}