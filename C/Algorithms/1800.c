int maxAscendingSum(int *nums, int numsSize) {
  if (numsSize == 1)
    return *nums;

  // Keep track of current sum and max found so far.
  int current_sum = 0, max_found = 0;
  for (int i = 0; i < numsSize - 1; i++) {
    int a = *(nums + i), b = *(nums + i + 1);
    current_sum += a;
    if (b <= a) {
      // update max if current exceeds it.
      if (current_sum > max_found)
        max_found = current_sum;
      current_sum = 0;
    }
  }

  // Check final value. Either it contributes to current or
  // it is the final value to compare to max_found.
  int final = nums[numsSize - 1];
  if (final > nums[numsSize - 2]) {
    current_sum += final;
    return max_found > current_sum ? max_found : current_sum;
  }
  return max_found > final ? max_found : final;
}