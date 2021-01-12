#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decode(int *encoded, int encodedSize, int first, int *returnSize) {
  // Re-use memory by allocating one more slot.
  *returnSize = encodedSize + 1;
  encoded = realloc(encoded, *returnSize * sizeof(*encoded));

  // And then taking care to place in correct positions.
  int next = first;
  for (int i = 1; i <= encodedSize; i++) {
    int tmp = encoded[i];
    encoded[i] = next ^ encoded[i - 1];
    next = tmp;
  }
  // Place first.
  encoded[0] = first;

  return encoded;
}
