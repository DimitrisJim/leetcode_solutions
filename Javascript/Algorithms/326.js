/**
 * @param {number} n
 * @return {boolean}
 */
let isPowerOfThree = n => {
  if (!(n & 1) || n <= 0) return false;
  const res = Math.log(n) / Math.log(3), diff = (Math.round(res) - res);
  return (diff < 0 ? -diff : diff) < 1e-10;
};