int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

// Hold first six values on n!.
static int facts[6] = {1, 2, 6, 24, 120, 720};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  *returnSize = facts[numsSize - 1];
  int **results = malloc(*returnSize * sizeof(*results)), len = numsSize - 1,
      resultsLen = 0;
  *returnColumnSizes = malloc(*returnSize * sizeof(**returnColumnSizes));

  // Sort nums to bring to least order.
  qsort(nums, numsSize, sizeof(*nums), cmpi);
  while (true) {
    // Copy nums over to results.
    results[resultsLen] = malloc(numsSize * sizeof(**results));
    for (int k = 0; k < numsSize; k++) {
      results[resultsLen][k] = nums[k];
    }
    (*returnColumnSizes)[resultsLen++] = numsSize;

    int i = len, j = len;
    // pos of shortest non-decreasing seq.
    while (i > 0) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
      i -= 1;
    }
    int k = 0;
    if (i > 0) {
      // find smallest value > nums[i-1]
      while (j >= i) {
        if (nums[j] > nums[i - 1])
          break;
        j--;
      }
      // Switch i-1 with j
      int tmp = nums[i - 1];
      nums[i - 1] = nums[j];
      nums[j] = tmp;

      // reverse *after* i
      k = i;
    } else
      break;

    // reverse rest of nums
    i = k;
    j = len;
    while (i < j) {
      int tmp = nums[i];
      nums[i++] = nums[j];
      nums[j--] = tmp;
    }
  }
  return results;
}