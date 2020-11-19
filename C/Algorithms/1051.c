#include <stdlib.h>
#include <string.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x, b = *(const int *)y;
  return (a > b) - (a < b);
}

int heightChecker(int *heights, int heightsSize) {
  // init, copy-over, sort.
  int *target = malloc(heightsSize * sizeof(*target));
  memcpy(target, heights, heightsSize * sizeof(*target));
  qsort(target, heightsSize, sizeof(*target), cmpi);

  // count diffs
  int diffs = 0;
  for (int i = 0; i < heightsSize; i++) {
    if (*(target + i) != *(heights + i))
      diffs++;
  }
  return diffs;
}
