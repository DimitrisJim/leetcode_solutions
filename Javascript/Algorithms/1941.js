/**
 * @param {string} s
 * @return {boolean}
 */
var areOccurrencesEqual = function(s) {
  let freqs = Array(26).fill(0);

  // hold on to first valid char and count frequencies.
  let c = s[0].charCodeAt() - 97;
  for (let char of s) freqs[char.charCodeAt() - 97]++;

  // check that all non zero values are equal to target.
  let target = freqs[c];
  for (let i = 0; i < 26; i++) {
    if (freqs[i] != 0) {
      if (freqs[i] != target) return false;
    }
  }
  return true;
};