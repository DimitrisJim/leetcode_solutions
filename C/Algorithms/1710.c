#include <stdlib.h>

// I really need to clear-up sorting of
// multidim arrays, it's a mess.
int cmpv(const void *x, const void *y) {
  const int *a = *(const int **)x;
  const int *b = *(const int **)y;

  return (a[1] > b[1]) - (a[1] < b[1]);
}

int maximumUnits(int **boxTypes, int boxTypesSize, int *boxTypesColSize,
                 int truckSize) {
  // Sort based on boxTypes[i][1] first.
  qsort(boxTypes, boxTypesSize, sizeof boxTypes[0], cmpv);

  // Count units (going backwards through boxTypes).
  int count = 0;
  while (truckSize && boxTypesSize--) {
    int num_b = boxTypes[boxTypesSize][0], num_u = boxTypes[boxTypesSize][1];
    // can add all units.
    if (num_b < truckSize) {
      count += num_b * num_u;
      truckSize -= num_b;
    } else {
      // Can't fit more than num_b boxes,
      // use truckSize boxes and return.
      return count + truckSize * num_u;
    }
  }
  return count;
}
