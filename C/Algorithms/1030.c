#include <stdlib.h>

#define ALLOC_N_PUT(vec, len, zero, one)                                       \
  vec[len] = malloc(2 * sizeof(int));                                          \
  vec[len][0] = zero;                                                          \
  vec[len++][1] = one;

int cmpv(const void *x, const void *y) {
  const int(*a)[2] = x;
  const int(*b)[2] = y;

  // Sort by sum of each sub-array.
  int sa = (*a)[0] + (*a)[1], sb = (*b)[0] + (*b)[1];
  return (sa > sb) - (sa < sb);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **allCellsDistOrder(int R, int C, int r0, int c0, int *returnSize,
                        int **returnColumnSizes) {
  int Rlim = ((R - r0) > r0 ? (R - r0) : r0) + 1,
      Clim = ((C - c0) > c0 ? (C - c0) : c0) + 1, length = 0;
  int(*indices)[2] = malloc(sizeof(int[Rlim * Clim][2]));

  for (int i = 0; i < Rlim; i++) {
    for (int j = 0; j < Clim; j++) {
      indices[length][0] = i;
      indices[length++][1] = j;
    }
  }
  // sort each element by its sum.
  qsort(indices, length, sizeof indices[0], cmpv);

  // Use double initially, might need to realloc.
  int size = length * 1.5, reslength = 0;
  int *retcols = malloc(size * sizeof(int));
  int **result = malloc(size * sizeof(*result));
  retcols[reslength] = 2;
  ALLOC_N_PUT(result, reslength, r0, c0);
  for (int k = 1; k < length; k++) {
    int i = indices[k][0], j = indices[k][1];
    int rpi = r0 + i, rmi = r0 - i;
    int cpj = c0 + j, cmj = c0 - j;

    // Allocate more space if needed.
    if (reslength + 4 >= size) {
      size *= 1.5;
      retcols = realloc(retcols, size * sizeof(*retcols));
      result = realloc(result, size * sizeof(*result));
    }
    // Add values:
    if (rmi >= 0) {
      if (cmj >= 0) {
        retcols[reslength] = 2;
        ALLOC_N_PUT(result, reslength, rmi, cmj);
      }
      if (j > 0 && cpj < C) {
        retcols[reslength] = 2;
        ALLOC_N_PUT(result, reslength, rmi, cpj);
      }
    }
    if (rpi < R && i > 0) {
      if (cpj < C) {
        retcols[reslength] = 2;
        ALLOC_N_PUT(result, reslength, rpi, cpj);
      }
      if (j > 0 && cmj >= 0) {
        retcols[reslength] = 2;
        ALLOC_N_PUT(result, reslength, rpi, cmj);
      }
    }
  }
  // Free, assign return pointers, return.
  free(indices);
  *returnColumnSizes = retcols;
  *returnSize = reslength;
  return result;
}
