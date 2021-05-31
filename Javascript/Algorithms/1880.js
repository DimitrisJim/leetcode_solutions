/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function(firstWord, secondWord, targetWord) {
  let asNum = s => {
    const pow = Math.pow;
    let length = s.length - 1, value = 0;
    for (let c of s) {
      c = c.charCodeAt() - 97;
      if (c > 0) value += pow(10, length) * c;
      length--;
    }
    return value;
  };
  return asNum(firstWord) + asNum(secondWord) == asNum(targetWord);
};