/**
 * @param {string} s
 * @return {number}
 */
var countGoodSubstrings = function(s) {
  let count = 0, i = 2, end = s.length;
  while (i < end) {
    let a = s[i - 2], b = s[i - 1], c = s[i];
    if (a == b && b == c) {
      i += 2;
      continue;
    }
    count += a != b && b != c && a != c;
    i++;
  }
  return count;
};