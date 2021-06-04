int findLengthOfLCIS(int *nums, int numsSize) {
  int seq_len = 1, max_len = 1, prev = nums[0];
  for (int i = 1; i < numsSize; i++) {
    int n = nums[i];
    if (n > prev) {
      seq_len++;
      if (seq_len > max_len)
        max_len = seq_len;
    } else
      seq_len = 1;
    prev = n;
  }
  return max_len;
}