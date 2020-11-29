#include <stdlib.h>
#include <string.h>

#define MAYBE_RESIZE(ptr, size, length)                                        \
  if (length >= size) {                                                        \
    size *= 2;                                                                 \
    ptr = realloc(ptr, size * sizeof(*ptr));                                   \
  }

#define MALLOC_N_COPY(dest, src, pos, size)                                    \
  dest[pos] = malloc(size);                                                    \
  strncpy(dest[pos++], src, size);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **buildArray(int *target, int targetSize, int n, int *returnSize) {
  char operations[2][5] = {"Push", "Pop"};
  int size = n / 2, length = 0, start = 0;
  char **stack_ops = malloc(size * sizeof(*stack_ops));

  for (int i = 0; i < targetSize; i++) {
    int val = target[i];
    int diff = val - start - 1;
    if (diff > 0) {
      for (int j = 0; j < diff; j++) {
        MAYBE_RESIZE(stack_ops, size, length + 2);
        MALLOC_N_COPY(stack_ops, operations[0], length, 5);
        MALLOC_N_COPY(stack_ops, operations[1], length, 4);
      }
    }
    MAYBE_RESIZE(stack_ops, size, length + 1);
    MALLOC_N_COPY(stack_ops, operations[0], length, 5);
    start = target[i];
  }
  *returnSize = length;
  return stack_ops;
}
