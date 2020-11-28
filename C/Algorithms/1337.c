#include <stdlib.h>

int cmpv(const void *x, const void *y) {
  const int(*a)[2] = x;
  const int(*b)[2] = y;
  return ((*a)[1] > (*b)[1]) - ((*a)[1] < (*b)[1]);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *kWeakestRows(int **mat, int matSize, int *matColSize, int k,
                  int *returnSize) {
  int inter[matSize][2];
  for (int i = 0; i < matSize; i++) {
    int sum = 0;
    for (int t = 0; t < *matColSize; t++)
      sum += mat[i][t];
    inter[i][0] = i;
    inter[i][1] = sum;
  }
  qsort(inter, matSize, sizeof inter[0], cmpv);

  *returnSize = k;
  int *res = malloc(k * sizeof(*res));
  for (int i = 0; i < k; i++)
    res[i] = inter[i][0];
  return res;
}
