/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
  let consecutive = 0, a_count = 0;
  for (let i of s) {
    if (i == 'L') {
      consecutive++;
      if (consecutive == 3) return false;
      continue;
    }
    if (i == 'A') {
      a_count++;
      if (a_count > 1) return false;
    }
    consecutive = 0;
  }
  return true;
};