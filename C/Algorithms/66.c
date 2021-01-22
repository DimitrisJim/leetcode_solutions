#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
  int i = digitsSize - 1;
  while (i >= 0) {
    if (digits[i] == 9) {
      digits[i] = 0;
      i--;
    } else {
      digits[i]++;
      break;
    }
  }
  *returnSize = digitsSize;
  if (i == -1 && digits[0] == 0) {
    // Add one more slot
    digits = realloc(digits, (digitsSize + 1) * sizeof(*digits));
    // don't reverse, fill first with 1 and last with 0.
    digits[0] = 1;
    digits[digitsSize] = 0;
    (*returnSize)++;
  }
  return digits;
}
