/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function(n) {
  if (((n & 1) || n <= 0) && (n != 1)) return false;

  const res = Math.log(n) / Math.log(4), diff = (Math.round(res) - res);
  return (diff < 0 ? -diff : diff) < 1e-10;
};