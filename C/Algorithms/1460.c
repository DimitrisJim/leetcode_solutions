#include <stdbool.h>
#include <stdlib.h>

// Sorting function
int cmpi(const void *x, const void *y) {
  int arg1 = *(const int *)x;
  int arg2 = *(const int *)y;

  return (arg1 > arg2) - (arg1 < arg2);
}

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize) {
  // Sort arrays.
  qsort(target, targetSize, sizeof(int), cmpi);
  qsort(arr, arrSize, sizeof(int), cmpi);

  // Element-wise compare.
  for (int i = 0; i < targetSize; i++) {
    if (*(arr + i) != *(target + i))
      return false;
  }
  return true;
}
