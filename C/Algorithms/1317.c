#include <stdlib.h>

inline int is_nozero(int i) {
  int d = 1000;
  // reduce d to appropriate value.
  while (i < d)
    d /= 10;
  while (d) {
    int q = i / d;
    if (!q)
      return 0;
    // reduce.
    i %= d, d /= 10;
  }
  return 1;
}

int *getNoZeroIntegers(int n, int *returnSize) {
  int *result = malloc(2 * sizeof(*result));
  *returnSize = 2;

  int upper = n, lower = 1;
  while (1) {
    int candidate = upper + lower;
    if (candidate == n) {
      result[0] = lower;
      result[1] = upper;
      return result;
    } else if (candidate < n) {
      while (!is_nozero(++lower))
        ;
    } else {
      while (!is_nozero(--upper))
        ;
    }
  }
}
