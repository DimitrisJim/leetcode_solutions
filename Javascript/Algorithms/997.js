/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
  let trust_list = Array(n).fill(0);
  trust.forEach(([p1, p2]) => {
    trust_list[p1 - 1] = -1;
    if (trust_list[p2 - 1] >= 0) trust_list[p2 - 1]++;
  });
  for (let i = 0; i < n; i++) {
    if (trust_list[i] == n - 1) return i + 1;
  }
  return -1;
};