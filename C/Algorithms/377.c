int combinationSum4(int *nums, int numsSize, int target) {
  int len = target + 1;
  unsigned long *a = calloc(len, sizeof(*a));
  a[0] = 1;
  for (int i = 0; i < len; i++) {
    if (a[i] == 0)
      continue;
    for (int j = 0; j < numsSize; j++) {
      int p = nums[j] + i;
      if (p < len) {
        a[p] += a[i];
      }
    }
  }
  int ret = a[len - 1];
  free(a);
  return ret;
}