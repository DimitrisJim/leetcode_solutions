/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  const max = Math.max;
  let maximum = nums[0], prev = 0;
  nums.forEach(num => {
    prev = max(num, prev + num);
    maximum = max(maximum, prev);
  });
  return maximum;
};