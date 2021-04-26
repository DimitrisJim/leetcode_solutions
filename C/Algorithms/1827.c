int minOperations(int *nums, int numsSize) {
  if (numsSize < 2)
    return 0;

  uint inc = 0;
  for (int i = 1; i < numsSize; i++) {
    int a = nums[i - 1], b = nums[i];
    if (a == b) {
      inc++;
      nums[i]++;
    } else if (a > b) {
      int diff = (a - b) + 1;
      inc += diff;
      nums[i] += diff;
    }
  }
  return inc;
}