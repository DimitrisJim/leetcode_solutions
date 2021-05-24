/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  // nums => indices
  indices = new Map;
  for (let i = 0; i < nums.length; i++) {
    const v = nums[i];
    if (indices.has(v)) {
      // check if diff is <= k, else replace index
      // with most recent seen.
      if (i - indices.get(v) > k)
        indices.set(v, i);
      else
        return true;
    } else
      indices.set(v, i);
  }
  return false;
};