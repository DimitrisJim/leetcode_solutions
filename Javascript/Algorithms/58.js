/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  let end = s.length - 1;
  while (s[end] == ' ') {
    if (--end == -1) return 0;
  }

  // We've reached the end of the last word (or returned).
  let count = 0;
  while (s[end] != ' ') {
    count++;
    if (--end == -1) break;
  }
  return count;
};