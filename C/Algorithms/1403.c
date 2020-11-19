#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x, b = *(const int *)y;
  return -((a > b) - (a < b));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *minSubsequence(int *nums, int numsSize, int *returnSize) {
  // Counters, sums.
  int i = 0, left_sum = 0, seq = 0;
  // Get sum.
  while (i < numsSize)
    left_sum += *(nums + i++);

  // sort nums.
  qsort(nums, numsSize, sizeof(int), cmpi);
  // Find subsequence.
  for (i = 0; i < numsSize; i++) {
    int val = *(nums + i);
    left_sum -= val;
    seq += val;
    if ((seq - left_sum) > 0) {
      break;
    }
  }
  *returnSize = i + 1;
  return nums;
}
