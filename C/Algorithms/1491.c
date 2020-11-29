#include <stdlib.h>

int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

double average(int *salary, int salarySize) {
  int count = salarySize - 2;
  qsort(salary, salarySize, sizeof(*salary), cmpi);
  int sum = 0;
  for (int i = 1; i < count + 1; i++) {
    sum += salary[i];
  }
  return (double)sum / (double)count;
}
