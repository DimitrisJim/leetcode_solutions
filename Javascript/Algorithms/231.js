/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
  if (n <= 0) {
    return false;
  }
  const res = Math.log2(n);
  return Math.ceil(res) == res;
};