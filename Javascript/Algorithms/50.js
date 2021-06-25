/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
  if (x == 0 || x == 1) return x;
  // flip sign of exponent.
  let pos_exp = true;
  if (n < 0) {
    pos_exp = false;
    n = -n;
  }

  let result = 1;
  while (n) {
    if (n & 1) result *= x;
    x *= x;
    n /= 2;
  }
  // a ** (-b) => 1 / a ** b
  return pos_exp ? result : 1 / result;
};