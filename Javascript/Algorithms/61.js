/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
  let mat = [];

  mat.push(Array(n).fill(1));
  for (let i = 1; i < m; i++) mat.push(Array(n).fill(0));

  for (let r = 1; r < m; r++) {
    for (let c = 0; c < n; c++) {
      mat[r][c] = mat[r - 1][c];
      if (c > 0) mat[r][c] += mat[r][c - 1];
    }
  }
  return mat[m - 1][n - 1];
};