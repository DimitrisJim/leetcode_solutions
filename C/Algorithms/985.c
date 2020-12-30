#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumEvenAfterQueries(int *A, int ASize, int **queries, int queriesSize,
                         int *queriesColSize, int *returnSize) {
  int evenSum = 0, v;
  for (int i = 0; i < ASize; i++) {
    v = *(A + i);
    if (v % 2 == 0)
      evenSum += v;
  }
  int *result = malloc(queriesSize * sizeof(*result)), r_idx = 0, idx,
      old_value, new_value;
  for (int i = 0; i < queriesSize; i++) {
    idx = queries[i][1];
    old_value = *(A + idx);
    new_value = old_value + queries[i][0];

    // add to evenSum if even:
    if (new_value % 2 == 0)
      evenSum += new_value;
    // subtract if old value was even
    if (old_value % 2 == 0)
      evenSum -= old_value;

    // Update A[idx], set to result.
    *(A + idx) = new_value;
    *(result + r_idx++) = evenSum;
  }
  *returnSize = queriesSize;
  return result;
}
