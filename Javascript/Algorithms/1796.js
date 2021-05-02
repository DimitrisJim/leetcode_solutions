/**
 * @param {string} s
 * @return {number}
 */
var secondHighest = function(s) {
  let max = '', second_max = '';
  for (let i = 0; i < s.length; i++) {
    let c = s[i];
    if (c > '' && c < 'a') {
      if (c > max) {
        if (max > second_max) second_max = max;
        max = c;
      } else if (c > second_max && c != max)
        second_max = c;
    }
  }
  return second_max == '' ? -1 : second_max.codePointAt() - 48;
};