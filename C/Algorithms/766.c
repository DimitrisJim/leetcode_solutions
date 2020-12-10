#include <stdbool.h>

bool isToeplitzMatrix(int **mat, int matrixSize, int *matrixColSize) {
  int cols = *matrixColSize - 1;
  for (int i = 0; i < matrixSize - 1; i++) {
    for (int j = 0; j < cols; j++) {
      if (mat[i][j] != mat[i + 1][j + 1]) {
        return false;
      }
    }
  }
  return true;
}
