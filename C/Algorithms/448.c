#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
  int *tmp = malloc(numsSize * sizeof(*tmp));
  for (int i = 1; i <= numsSize; i++)
    *(tmp + i - 1) = i;

  int length = 0;
  for (int i = 0; i < numsSize; i++) {
    int index = nums[i];
    if (*(tmp + index - 1) == 0)
      length++;
    *(tmp + index - 1) = 0;
  }

  *returnSize = length;
  int *ret = malloc(length * sizeof(*ret));
  for (int i = 0, j = 0; i < numsSize; i++) {
    if (tmp[i])
      ret[j++] = tmp[i];
  }
  free(tmp);
  return ret;
}
