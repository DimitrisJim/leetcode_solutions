#include <stdbool.h>

bool isMonotonic(int *A, int ASize) {
  int decreases = -1;
  for (int i = 0; i < ASize - 1; i++) {
    int a = A[i], b = A[i + 1];
    if (a != b) {
      if (decreases == -1) {
        decreases = a > b;
        continue;
      }
      if ((a > b) != decreases)
        return 0;
    }
  }
  return 1;
}
