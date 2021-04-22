let isPalindrome = function(x) {
  if (x < 0) return false
    let s = `${x}`, [i, j] = [0, s.length - 1];
  while (i < j) {
    if (s[i++] != s[j--]) return false
  }
  return true;
};