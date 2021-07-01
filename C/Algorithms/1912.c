int maxProductDifference(int *nums, int numsSize) {
  // a, b hold 1st and 2nd maxes
  int a = 0, b = 0;
  // c, d hold 1st and 2nd mins
  int c = 10 << 10, d = c;
  for (int i = 0; i < numsSize; i++) {
    int num = nums[i];
    if (num >= a) {
      int tmp = a;
      a = num;
      b = tmp;
    } else if (num > b)
      b = num;
    if (num <= c) {
      int tmp = c;
      c = num;
      d = tmp;
    } else if (num < d)
      d = num;
  }
  return a * b - c * d;
}