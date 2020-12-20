#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize) {
  char *fizzBuzz[] = {"Fizz", "Buzz", "FizzBuzz"};
  char **res = malloc(n * sizeof(*res));
  for (int i = 1; i < n + 1; i++) {
    int r = i / 3, m = i % 3;
    if (m == 0) {
      int t = r % 5;
      res[i - 1] = malloc(t ? 5 : 9);
      strncpy(res[i - 1], fizzBuzz[t ? 0 : 2], t ? 5 : 9);
    } else {
      int t = i % 5;
      if (t) {
        // Use snprintf to get length and place into
        // res.
        int length = snprintf(NULL, 0, "%d", i) + 1;
        res[i - 1] = malloc(length);
        snprintf(res[i - 1], length, "%d", i);
      } else {
        res[i - 1] = malloc(5);
        strncpy(res[i - 1], fizzBuzz[1], 5);
      }
    }
  }
  *returnSize = n;
  return res;
}
