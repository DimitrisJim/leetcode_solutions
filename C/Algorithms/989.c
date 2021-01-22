#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addToArrayForm(int *A, int ASize, int K, int *returnSize) {
  int i = ASize;
  while (--i >= 0 && K) {
    int r = K % 10;
    K = K / 10;
    int sum = A[i] + r;
    if (sum > 9) {
      A[i] = sum % 10;
      K++;
    } else
      A[i] = sum;
  }

  // Make sure we have nothing else to add.
  if (K > 0) {
    // Fill tmp up with remaining digits in K.
    int size = 5, length = 0;
    int *tmp = malloc(size * sizeof(*tmp));
    while (K) {
      int r = K % 10;
      K = K / 10;
      if (length + 1 == size) {
        size *= 1.5;
        tmp = realloc(tmp, size * sizeof(*tmp));
      }
      tmp[length++] = r;
    }
    // Reverse tmp
    int mid = length / 2;
    for (int i = 0; i < mid; i++) {
      int t = tmp[length - i - 1];
      tmp[length - i - 1] = tmp[i];
      tmp[i] = t;
    }
    // Add A to end of reversed tmp.
    *returnSize = ASize + length;
    tmp = realloc(tmp, (*returnSize) * sizeof(*tmp));
    for (int i = length, j = 0; i < *returnSize; i++, j++)
      tmp[i] = A[j];
    return tmp;
  }
  // Nothing more to add.
  *returnSize = ASize;
  return A;
}
