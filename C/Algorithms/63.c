

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize,
                             int *obstacleGridColSize) {
  int m = obstacleGridSize, n = obstacleGridColSize[0];
  if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
    return 0;

  // Alloc matrix.
  unsigned **mat = malloc(m * sizeof(*mat));
  for (int i = 0; i < m; i++)
    mat[i] = calloc(n, sizeof(**mat));
  mat[0][0] = 1;

  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      // Don't do anything if we land on obstacle.
      if (obstacleGrid[r][c])
        continue;

      // Check top and left.
      if (r > 0 && obstacleGrid[r - 1][c] == 0)
        mat[r][c] = mat[r - 1][c];
      if (c > 0 && obstacleGrid[r][c - 1] == 0)
        mat[r][c] += mat[r][c - 1];
    }
  }
  // Result @ final pos of mat. Free and return.
  long res = mat[m - 1][n - 1];
  for (int i = 0; i < m; i++)
    free(mat[i]);
  free(mat);
  return res;
}