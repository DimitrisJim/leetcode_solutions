/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
  let s = new Set(brokenLetters), count = 0;

  for (let w of text.split(' ')) {
    for (let c of w) {
      if (s.has(c)) {
        count--;
        break;
      }
    }
    count++;
  }
  return count;
};