#include <stdbool.h>
#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x, b = *(const int *)y;
  return (a > b) - (a < b);
}

bool canMakeArithmeticProgression(int *arr, int arrSize) {
  qsort(arr, arrSize, sizeof(int), cmpi);
  int step = arr[1] - arr[0];
  for (int i = 2; i < arrSize; i++) {
    if (*(arr + i) != *(arr + i - 1) + step)
      return false;
  }
  return true;
}
