bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
                  int target) {
  int n = matrixSize - 1, j = 0;
  while (n >= 0 && j < matrixColSize[0]) {
    int value = matrix[n][j];
    if (value == target)
      return true;
    if (value > target)
      n--;
    else
      j++;
  }
  return false;
}