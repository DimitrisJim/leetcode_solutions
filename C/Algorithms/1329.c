#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (b > a) - (b < a);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **diagonalSort(int **mat, int matSize, int *matColSize, int *returnSize,
                   int **returnColumnSizes) {
  int rows = matSize - 1, cols = matColSize[0] - 1,
      // max size of diag is == rows.
                              *diag = malloc(matSize * sizeof(*diag)),
      diagLen = 0;
  // start from bottom left corner.
  int r = rows, c = 0;
  while (r != 0 || c != cols) {
    // Grab diagonal.
    int i = r, j = c;
    while (i <= rows && j <= cols)
      diag[diagLen++] = mat[i++][j++];

    // sort until diagLen.
    if (diagLen > 1)
      qsort(diag, diagLen, sizeof(*diag), cmpi);

    // Place back.
    i = r, j = c;
    while (i <= rows && j <= cols)
      mat[i++][j++] = diag[--diagLen];

    // Increment r, c
    if (r == 0)
      c++;
    if (r > 0)
      r--;
  }
  // Free and resign return values.
  free(diag);
  *returnColumnSizes = matColSize;
  *returnSize = matSize;
  return mat;
}
