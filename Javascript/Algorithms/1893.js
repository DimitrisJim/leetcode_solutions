/**
 * @param {number[][]} ranges
 * @param {number} left
 * @param {number} right
 * @return {boolean}
 */
var isCovered = function(ranges, left, right) {
  ranges.sort((a, b) => a[1] - b[1]);
  let i = 0;
  while (left <= right && i < ranges.length) {
    let l = ranges[i][0];
    let r = ranges[i][1];
    if (l <= left && left <= r) left = r + 1;
    if (l <= right && right <= r) right = l - 1;
    i++;
  }
  return left > right;
};