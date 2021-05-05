/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize) {
  *returnSize = 2;
  int *result = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    int index = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
    if (nums[index] < 0) {
      result[0] = index + 1;
      // don't change index back
      continue;
    }
    nums[index] = -nums[index];
  }
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0) {
      result[1] = i + 1;
      break;
    }
  }
  return result;
}