/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
  const res = [0, 0], abs = Math.abs;
  for (let i of nums) {
    let index = abs(i) - 1;
    if (nums[index] < 0) {
      res[0] = index + 1;
      continue;
    }
    nums[index] = -nums[index];
  }

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) {
      res[1] = i + 1;
      break;
    }
  }
  return res;
};