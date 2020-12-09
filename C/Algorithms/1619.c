#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

double trimMean(int *arr, int arrSize) {
  int trim = arrSize * 0.05;
  // sort
  qsort(arr, arrSize, sizeof(*arr), cmpi);
  // sum
  int sum = 0;
  for (int i = trim; i < arrSize - trim; i++) {
    sum += arr[i];
  }
  // return mean.
  return (double)sum / (double)(arrSize - 2 * trim);
}
