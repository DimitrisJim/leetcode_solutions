#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (b > a) - (b < a);
}

int largestPerimeter(int *A, int ASize) {
  int lim = ASize - 2;
  qsort(A, ASize, sizeof(*A), cmpi);

  for (int i = 0; i < lim; i++) {
    int a = *(A + i), b = *(A + i + 1), c = *(A + i + 2);
    if (a + b > c && b + c > a && c + a > b) {
      return a + b + c;
    }
  }
  return 0;
}
