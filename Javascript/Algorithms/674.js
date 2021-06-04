/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(nums) {
  let seq_len = 1, max_len = 1, prev = nums[0];
  nums.forEach(n => {
    if (n > prev) {
      seq_len++;
      if (seq_len > max_len) max_len = seq_len;
    } else
      seq_len = 1;
    prev = n;
  });
  return max_len;
};