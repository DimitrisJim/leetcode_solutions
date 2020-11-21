#include <stdlib.h>
#include <string.h>

int minDeletionSize(char **A, int ASize) {
  int rlen = strlen(A[0]);
  int *indices = calloc(rlen, sizeof(*indices));

  for (int i = 0; i < ASize - 1; i++) {
    char *row_a = A[i];
    char *row_b = A[i + 1];

    for (int j = 0; j < rlen; j++) {
      if (!*(indices + j)) {
        if (row_b[j] < row_a[j]) {
          *(indices + j) = 1;
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < rlen; i++) {
    sum += *(indices + i);
  }
  free(indices);
  return sum;
}
