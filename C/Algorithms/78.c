/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **subsets(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  int size = 1 << numsSize;
  int **result = malloc(size * sizeof(*result));
  *returnColumnSizes = malloc(size * sizeof(**returnColumnSizes));

  (*returnColumnSizes)[0] = 0;
  for (int i = 1; i < size; i++) {
    (*returnColumnSizes)[i] = 0;
    int *col = &(*returnColumnSizes)[i];
    result[i] = malloc(0);
    for (int j = 0; j < numsSize; j++) {
      if (i & (1 << j)) {
        (*col)++;
        result[i] = realloc(result[i], *col * sizeof(result[i]));
        result[i][*col - 1] = nums[j];
      }
    }
  }
  *returnSize = size;
  return result;
}