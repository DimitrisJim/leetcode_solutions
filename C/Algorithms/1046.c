#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

int lastStoneWeight(int *stones, int stonesSize) {
  while (1) {
    qsort(stones, stonesSize, sizeof(int), cmpi);
    if (stonesSize >= 2) {
      int e1 = stones[stonesSize - 1];
      int diff = e1 - stones[stonesSize - 2];
      if (diff) {
        stones[stonesSize - 2] = diff;
        stonesSize -= 1;
      } else
        stonesSize -= 2;
    } else {
      if (stonesSize == 0)
        return 0;
      else if (stonesSize == 1) {
        return stones[0];
      }
    }
  }
  // unreachable.
  return 0;
}
