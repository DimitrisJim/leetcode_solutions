/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
  const length = nums.length;
  size = 1 << length, result = [[]];

  for (let i = 1; i < size; i++) {
    let sub = [];
    for (let j = 0; j < length; j++) {
      if (i & (1 << j)) {
        sub.push(nums[j]);
      }
    }
    result.push(sub);
  }
  return result;
};