#include <stdlib.h>

int getMaximumGenerated(int n) {
  if (n < 2)
    return n;

  int *A = malloc((n + 1) * sizeof(*A)), max = 0;
  A[0] = 0;
  A[1] = 1;

  for (int i = 2; i <= n; i++) {
    int q = i / 2, r = i % 2;
    int val = A[q];
    if (val > max)
      max = val;
    if (r) {
      int add = val + A[q + 1];
      if (add > max)
        max = add;
      A[i] = add;
    } else {
      A[i] = val;
    }
  }
  free(A);
  return max;
}
