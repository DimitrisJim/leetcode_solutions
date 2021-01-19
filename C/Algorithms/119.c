#include <math.h>
#include <stdlib.h>

int *getRow(int n, int *returnSize) {
  int *result = malloc((n + 1) * sizeof(*result));
  *returnSize = n + 1;
  result[0] = 1;

  // Use symmetry of rows.
  int odd = 0, mid;
  if ((n + 1) & 1) {
    odd = 1;
    mid = ((n + 1) / 2 + 1);
  } else {
    mid = ((n + 1) / 2);
  }
  // Fill until mid point.
  for (int k = 1; k < mid; k++) {
    int previous = result[k - 1];
    // Need double cast, else precision costs.
    result[k] = round(previous * ((double)(n + 1 - k) / k));
  }
  // Manually reverse and add to end of result.
  int end = odd ? mid - 1 : mid;
  for (int i = 0; i < end; i++) {
    result[n--] = result[i];
  }
  return result;
}
