#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **transpose(int **A, int ASize, int *AColSize, int *returnSize,
                int **returnColumnSizes) {
  int columns = *AColSize;
  int **result = malloc(columns * sizeof(*result));
  *returnColumnSizes = malloc(columns * sizeof(**returnColumnSizes));

  for (int i = 0; i < columns; i++) {
    result[i] = malloc(ASize * sizeof(**result));
    (*returnColumnSizes)[i] = ASize;
    for (int j = 0; j < ASize; j++) {
      // transpose
      result[i][j] = A[j][i];
    }
  }
  *returnSize = columns;
  return result;
}
