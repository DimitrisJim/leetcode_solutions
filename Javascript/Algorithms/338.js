/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
  let res = Array(++n).fill(0);
  for (let i = 1; i < n; i++) {
    // i >> 1 will always be smaller than `i` and
    // present in the array.
    // i & 1 checks if we shifted off a zero or a one
    // (and, respectively adds 0 or 1 to the result)
    res[i] = res[i >> 1] + (i & 1);
  }
  return res;
};