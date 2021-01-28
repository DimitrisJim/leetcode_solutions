#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

int maxWidthOfVerticalArea(int **points, int pointsSize, int *pointsColSize) {
  int *x_points = malloc(pointsSize * sizeof(*x_points));
  for (int i = 0; i < pointsSize; i++)
    x_points[i] = points[i][0];

  qsort(x_points, pointsSize, sizeof(*x_points), cmpi);
  int max = 0;
  for (int i = 0; i < pointsSize - 1; i++) {
    int diff = x_points[i + 1] - x_points[i];
    if (diff > max)
      max = diff;
  }
  return max;
}
