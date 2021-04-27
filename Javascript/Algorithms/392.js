/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
  let start_index = 0;
  for (let c of s) {
    start_index = t.indexOf(c, start_index);
    if (start_index == -1)
      return false;
    else
      start_index++;
  }
  return true;
};