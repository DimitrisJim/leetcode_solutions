/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
  if (nums.length < 2) return 0;

  let inc = 0;
  for (let i = 1; i < nums.length; i++) {
    const a = nums[i - 1], b = nums[i];
    if (a == b) {
      inc++;
      nums[i]++;
    } else if (a > b) {
      let diff = (a - b) + 1;
      inc += diff;
      nums[i] += diff;
    }
  }
  return inc;
};