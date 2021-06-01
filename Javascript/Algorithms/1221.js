/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {
  let count = 0, cur_char = s[0], track = 1;
  let i = 1, end = s.length;
  while (i < end) {
    let next_char = s[i];
    if (next_char != cur_char) {
      track--;
      if (track == 0) {
        count++;
        i++;
        if (i < end) {
          cur_char = s[i];
          track = 1;
        } else
          break;
      }
    } else
      track++;
    i++;
  }
  return count;
};