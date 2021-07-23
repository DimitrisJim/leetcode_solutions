/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
  let m = obstacleGrid.length, n = obstacleGrid[0].length;
  if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

  let mat = [];
  for (let i = 0; i < m; i++) mat.push(Array(n).fill(0));
  mat[0][0] = 1;

  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      // if at obstacle, continue.
      if (obstacleGrid[r][c]) continue;

      // Add top/left if possible.
      if (r > 0 && obstacleGrid[r - 1][c] == 0) mat[r][c] = mat[r - 1][c];
      if (c > 0 && obstacleGrid[r][c - 1] == 0) mat[r][c] += mat[r][c - 1];
    }
  }
  return mat[m - 1][n - 1];
};