#include <stdlib.h>

#define ADD_FROM_RANGE(rng, arr)                                               \
  int s = rng[0], e = rng[1];                                                  \
  for (int i = s; i <= e; i++)                                                 \
    tmp[i - 1]++;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *mostVisited(int n, int *rounds, int roundsSize, int *returnSize) {
  int i = 0, begin[2] = {0, 0};
  // If i == 1, we start from the beginning and can just skip this,
  // if not, we need to see where we started from since those sectors
  // will have been visited +1 times.
  if (rounds[i] != 1) {
    int start = rounds[i];
    while (i < (roundsSize - 1) && rounds[i] < rounds[i + 1])
      i++;

    // return early, reached end.
    if (i == roundsSize - 1) {
      *returnSize = (rounds[i] - start) + 1;
      int *result = malloc(*returnSize * sizeof(*result));
      for (int j = start; j <= rounds[i]; j++)
        result[j - start] = j;
      return result;
    }
    begin[0] = start;
    begin[1] = n;
  }
  // Grab trailing (last marathon).
  int trail[2] = {1, rounds[roundsSize - 1]}, *tmp = calloc(n, sizeof(*tmp));

  if (begin[0] != 0) {
    ADD_FROM_RANGE(begin, tmp);
  }
  ADD_FROM_RANGE(trail, tmp);
  // Find max + how many elements == max.
  int max = 0, retSize = 0, retlen = 0;
  for (int i = 0; i < n; i++) {
    int v = tmp[i];
    if (v >= max)
      max = v;
  }
  for (int i = 0; i < n; i++) {
    if (*(tmp + i) == max)
      retSize++;
  }
  // Create return array and fill.
  *returnSize = retSize;
  int *ret = malloc(retSize * sizeof(*ret));
  for (int i = 0; i < n; i++) {
    if (tmp[i] == max)
      ret[retlen++] = i + 1;
  }
  free(tmp);
  return ret;
}
