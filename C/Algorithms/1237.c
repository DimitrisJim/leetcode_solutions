#include <stdlib.h>

/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **findSolution(int (*customFunction)(int, int), int z, int *returnSize,
                   int **returnColumnSizes) {
  int size = 15, length = 0;
  // Initialize an initial size of 15.
  int **res = malloc(size * sizeof(*res));
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j < 101; j++) {
      int result = customFunction(i, j);
      if (result == z) {
        // realloc if necessary.
        if (length == size - 1) {
          size *= 1.5;
          res = realloc(res, size * sizeof(*res));
        }
        // Assign values to res.
        res[length] = malloc(sizeof(int) * 2);
        res[length][0] = i;
        res[length++][1] = j;
      }
      if (result > z) {
        break;
      }
    }
  }
  // Assign to columns (all 2's)
  *returnColumnSizes = malloc(length * sizeof(**returnColumnSizes));
  for (int i = 0; i < length; i++)
    (*returnColumnSizes)[i] = 2;
  // return.
  *returnSize = length;
  return res;
}
