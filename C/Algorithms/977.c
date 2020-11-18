#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize) {
  for (int i = 0; i < ASize; i++) {
    A[i] = A[i] * A[i];
  }
  qsort(A, ASize, sizeof(*A), cmpi);
  *returnSize = ASize;
  return A;
}
