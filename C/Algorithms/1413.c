int minStartValue(int *nums, int numsSize) {
  int min = 1, cur = 1;
  for (int i = 0; i < numsSize; i++) {
    int val = nums[i];
    int diff = 1 - (cur + val);
    if (diff > 0) {
      min += diff;
      cur += diff;
    }
    cur += val;
  }
  return min;
}
