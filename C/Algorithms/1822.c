int arraySign(int *nums, int numsSize) {
  int res = 1;
  for (int i = 0; i < numsSize; i++) {
    int val = *(nums + i);
    if (val == 0)
      return 0;
    if (val < 0)
      res = -res;
  }
  return res;
}