/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
  nums = nums.map((v, i) => [i, v]);
  nums.sort((a, b) => a[1] - b[1]);
  const abs = Math.abs;

  for (let i = 0; i < nums.length; i++) {
    let j = i + 1;
    while (j < nums.length && (nums[j][1] - nums[i][1] <= t)) {
      if (abs(nums[j][0] - nums[i][0]) <= k) {
        return true;
      }
      j++;
    }
  }
  return false;
};