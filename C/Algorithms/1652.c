#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decrypt(int *code, int codeSize, int k, int *returnSize) {
  int *result = calloc(codeSize, sizeof(*result));
  if (k != 0) {
    int K = k > 0 ? k : -k;
    for (int i = 0; i < codeSize; i++) {
      int sum = 0;
      for (int j = 0; j < K; j++) {
        if (k > 0)
          sum += code[(i + 1 + j) % codeSize];
        else {
          int idx = i - j - 1;
          sum += code[idx >= 0 ? idx : codeSize + idx];
        }
      }
      result[i] = sum;
    }
  }
  *returnSize = codeSize;
  return result;
}
