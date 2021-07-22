int uniquePaths(int m, int n) {
  unsigned **mat = malloc(m * sizeof(*mat));
  for (int i = 0; i < m; i++)
    mat[i] = calloc(n, sizeof(**mat));
  mat[0][0] = 1;

  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      if (r > 0)
        mat[r][c] = mat[r - 1][c];
      if (c > 0)
        mat[r][c] += mat[r][c - 1];
    }
  }
  long res = mat[m - 1][n - 1];
  for (int i = 0; i < m; i++)
    free(mat[i]);
  free(mat);
  return res;
}