/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  let length = nums.length - 1;
  let i = length, j = length;
  // pos of shortest non-decreasing seq.
  while (i > 0) {
    if (nums[i - 1] < nums[i]) break;
    i--;
  }
  let k = 0;
  if (i > 0) {
    // find smallest value > nums[i-1]
    while (j >= i) {
      if (nums[j] > nums[i - 1]) break;
      j--;
    }
    // Switch i-1 with j
    let tmp = nums[i - 1];
    nums[i - 1] = nums[j];
    nums[j] = tmp;
    // reverse *after* i
    k = i;
  }
  // reverse rest of nums
  for (let i = k, j = length; i < j; i++, j--) {
    let tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};