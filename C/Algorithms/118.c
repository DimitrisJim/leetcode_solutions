#include <math.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 *
 * See:
 * https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
  // Initialize return array and columns array.
  int **res = malloc((numRows + 1) * sizeof(*res));
  *returnColumnSizes = malloc((numRows + 1) * sizeof(**returnColumnSizes));
  for (int n = 0; n < numRows; n++) {
    // Initialize inner array and set value for column.
    int *inner = malloc((n + 1) * sizeof(*inner));
    (*returnColumnSizes)[n] = n + 1;
    inner[0] = 1;

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
      int previous = inner[k - 1];
      // Need double cast, else precision costs.
      inner[k] = round(previous * ((double)(n + 1 - k) / k));
    }
    // Manually reverse inner.
    int end = odd ? mid - 1 : mid;
    int size = n;
    for (int i = 0; i < end; i++) {
      inner[size--] = inner[i];
    }
    res[n] = inner;
  }
  *returnSize = numRows;
  return res;
}
