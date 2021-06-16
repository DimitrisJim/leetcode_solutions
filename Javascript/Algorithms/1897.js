/**
 * @param {string[]} words
 * @return {boolean}
 */
var makeEqual = function(words) {
  // Build count of characters.
  let charCount = Array(26).fill(0);
  words.forEach(word => {
    for (let char of word) charCount[char.codePointAt() - 97]++;
  });
  // Assert that we can distribute these evenly (char count % length == 0)
  const length = words.length;
  for (let count of charCount) {
    if (count % length) return false;
  }
  return true;
};