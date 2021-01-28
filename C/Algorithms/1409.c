#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *processQueries(int *queries, int queriesSize, int m, int *returnSize) {
  int *P = malloc(m * sizeof(*P)),
      *result = malloc(queriesSize * sizeof(*result));

  // fill P up:
  for (int i = 1; i < m + 1; i++)
    *(P + i - 1) = i;

  for (int i = 0; i < queriesSize; i++) {
    // Find query in P and put into result.
    int q = queries[i], q_idx = 0;
    while (*(P + q_idx++) != q)
      ;
    *(result + i) = q_idx - 1;

    // Remove-place at beginning with one loop.
    int i = 0, previous = q;
    while (1) {
      int tmp = *(P + i);
      *(P + i++) = previous;
      previous = tmp;
      // break when we reach old q (which should now be replaced.)
      if (previous == q)
        break;
    }
  }
  free(P);
  *returnSize = queriesSize;
  return result;
}
