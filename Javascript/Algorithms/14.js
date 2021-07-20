/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  let prefix = strs[0];
  for (let k = 1; k < strs.length; k++) {
    let s = strs[k];

    let i = 0, end = Math.min(prefix.length, s.length);
    while (i < end && s[i] == prefix[i]) i++;
    if (i == 0) {
      return '';
    }
    prefix = prefix.slice(0, i);
  }
  return prefix;
};