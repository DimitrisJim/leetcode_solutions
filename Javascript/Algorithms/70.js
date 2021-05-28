/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
  if (n == 1) return 1;
  let a = 1, b = 2;
  n--;
  while (--n > 0) {
    let temp = b;
    b = a + b;
    a = temp;
  }
  return b;
};