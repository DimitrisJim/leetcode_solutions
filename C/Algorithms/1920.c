/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *buildArray(int *nums, int numsSize, int *returnSize) {
  int *res = malloc(numsSize * sizeof(*res));

  for (int i = 0; i < numsSize; i++) {
    res[i] = nums[nums[i]];
  }
  *returnSize = numsSize;
  return res;
}