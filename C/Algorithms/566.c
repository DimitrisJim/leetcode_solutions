#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **matrixReshape(int **nums, int numsSize, int *numsColSize, int r, int c,
                    int *returnSize, int **returnColumnSizes) {
  int old_cols = numsColSize[0];
  // Can't fit into new dimensions.
  if ((numsSize * old_cols) != (r * c)) {
    *returnColumnSizes = numsColSize;
    *returnSize = numsSize;
    return nums;
  }

  // Result arrays.
  int **result = malloc(r * sizeof(*result)), k = 0, z = 0;
  *returnColumnSizes = malloc(r * sizeof(**returnColumnSizes));
  // Fill from nums.
  for (int i = 0; i < r; i++) {
    result[i] = malloc(c * sizeof(**result));
    (*returnColumnSizes)[i] = c;
    for (int j = 0; j < c; j++) {
      result[i][j] = nums[k][z++];
      if (z == old_cols) {
        z = 0;
        k++;
      }
    }
  }
  *returnSize = r;
  return result;
}
