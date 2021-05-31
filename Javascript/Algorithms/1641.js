/**
 * @param {number} n
 * @return {number}
 */
var countVowelStrings = function(n) {
  let a = 5, e = 4, i = 3, o = 1;
  while (++o <= n) {
    i += o + 1;
    e += i;
    a += e;
  }
  return a;
};