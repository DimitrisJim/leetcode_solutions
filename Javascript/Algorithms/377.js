/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function(nums, target) {
  let len = target + 1, a = Array(len).fill(0);
  a[0] = 1;
  for (let i = 0; i < len; i++) {
    if (a[i] == 0) continue;
    for (let v of nums) {
      if ((v + i) < len) {
        a[v + i] += a[i];
      }
    }
  }
  return a[len - 1];
};