/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
  let n = matrix.length - 1, m = matrix[0].length, j = 0;
  while (n >= 0 && j < m) {
    const value = matrix[n][j];
    if (value == target) return true;
    if (value > target)
      n--;
    else
      j++;
  }
  return false;
};