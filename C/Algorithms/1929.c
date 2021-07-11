/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize * 2;
  nums = realloc(nums, *returnSize * sizeof(*nums));
  memcpy(nums + numsSize, nums, numsSize * sizeof(*nums));

  return nums;
}