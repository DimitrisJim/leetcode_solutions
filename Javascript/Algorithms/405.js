/**
 * @param {number} num
 * @return {string}
 */
let toHex = n => {
  // Edge case.
  if (n == 0) return '0';

  let size = 8;
  const map = [...'0123456789abcdef'], res = [];
  while (n && size > 0) {
    res.push(map[n & 15]);
    n >>= 4;
    size--;
  }
  return res.reverse().join('');
};