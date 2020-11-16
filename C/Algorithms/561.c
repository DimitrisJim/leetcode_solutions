#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

int arrayPairSum(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmpi);
  unsigned sum = 0;
  while (numsSize--)
    sum += nums[--numsSize];
  return sum;
}
