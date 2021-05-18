/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function(s) {
  const words = s.split(' '), result = Array(words.length);

  words.forEach((w) => {
    result[parseInt(w.slice(-1))] = w.slice(0, -1);
  });
  return result.join(' ').trimLeft();
};