/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
  const floor = Math.floor;
  // Build a count of letters (note, need extra space because some
  // non-letter chars follow uppercase ones.)
  let letters = Array(58).fill(0);
  for (let c of s) letters[c.charCodeAt() - 65]++;

  let length = 0, add = 0;
  letters.forEach(count => {
    if (count & 1) {
      add = 1;
      length--;
    }
    length += count;
  });
  return length + add;
};