/**
 * @param {string} word
 * @return {number}
 */
var numDifferentIntegers = function(word) {
  let seen = new Set;
  for (let match of word.matchAll('[0-9]+')) {
    let i = 0, num = match[0];
    // Trim off leading zeroes.
    while (num[i] == 0) i++;
    seen.add(num.slice(i));
  }
  return seen.size;
};