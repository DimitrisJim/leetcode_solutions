#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize,
                       int *returnSize) {
  int *target = malloc(numsSize * sizeof(*target)), length = 0;

  for (int i = 0; i < numsSize; i++) {
    int idx = index[i], value = nums[i];
    // Only shift when needed (i.e we try and place
    // a new item in a position already occupied as indicated
    // by length.)
    if (idx < length) {
      int k = idx;
      while (k < numsSize) {
        int tmp = target[k];
        target[k] = value;
        value = tmp;
        k++;
      }
      // Else, if possible, just add it.
    } else
      target[idx] = value;
    length++;
  }

  *returnSize = numsSize;
  return target;
}
