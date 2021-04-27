/**
 * @param {number} num
 * @return {string}
 */
var convertToBase7 = function(n) {
  if (n == 0) return '0';

  let [num, neg] = n > 0 ? [n, false] : [-n, true];
  const res = [], floor = Math.floor;
  while (num) {
    res.push(num % 7);
    num = floor(num / 7);
  }
  if (neg) res.push('-');
  res.reverse();
  return res.join('');
};