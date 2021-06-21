/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function(num) {
  let set = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1];
  for (let i = num.length - 1; i >= 0; i--) {
    if (set[num[i].codePointAt() - 48]) return num.slice(0, i + 1);
  }
  return '';
};