/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
  const m = matrix[0].length, floor = Math.floor;
  for (row of matrix) {
    // Don't search in rows where final element is < target.
    if (target > row[m - 1]) continue;

    let lo = 0, hi = m;
    while (lo < hi) {
      let mid = floor((lo + hi) / 2);
      if (row[mid] < target)
        lo = mid + 1;
      else {
        if (row[mid] == target) return true;
        hi = mid;
      }
    }
  }
  return false;
};