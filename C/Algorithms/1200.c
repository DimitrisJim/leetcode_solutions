#include <limits.h>
#include <stdlib.h>

#define ABS(X) (X < 0) ? -X : X

#define ALLOC_N_PUT(res, length, x, y)                                         \
  res[length] = malloc(2 * sizeof(int));                                       \
  res[length][0] = x;                                                          \
  res[length++][1] = y;

// Compare function for qsort.
int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **minimumAbsDifference(int *arr, int arrSize, int *returnSize,
                           int **returnColumnSizes) {
  int min_diff = INT_MAX, size = (arrSize / 10) + 4, length = 0;
  // Initialize arrays.
  int **result = malloc(size * sizeof(*result));
  int *cols = malloc(size * sizeof(*cols));

  // Sort, ascending.
  qsort(arr, arrSize, sizeof(*arr), cmpi);

  // Go through pairs and add those with minimum differences.
  for (int k = 0; k < arrSize - 1; k++) {
    int i = arr[k + 1], j = arr[k];
    int diff = ABS(i - j);
    if (diff < min_diff) {
      // Free stuff we've already happened to allocate.
      for (int t = 0; t < length; t++)
        free(result[t]);
      // No need to resize in here, we go to zero again.
      length = 0;
      min_diff = diff;
      *(cols + length) = 2;
      ALLOC_N_PUT(result, length, j, i);
    } else if (diff == min_diff) {
      // Resize if necessary.
      if (length + 1 >= size) {
        size *= 1.5;
        cols = realloc(cols, size * sizeof(*cols));
        result = realloc(result, size * sizeof(*result));
      }
      *(cols + length) = 2;
      ALLOC_N_PUT(result, length, j, i);
    }
  }
  // They free cols.
  *returnColumnSizes = cols;
  *returnSize = length;
  return result;
}
