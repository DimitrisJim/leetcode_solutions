/**
 * @param {string} word
 * @return {number}
 */
var minTimeToType = function(word) {
  let result = word.length, prev = 97, abs = Math.abs, min = Math.min;
  for (let c of word) {
    let next = c.codePointAt();
    let dst = abs(prev - next);
    result += min(dst, 26 - dst);
    prev = next;
  }
  return result;
};