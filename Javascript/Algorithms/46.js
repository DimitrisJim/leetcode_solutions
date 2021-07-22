/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  nums.sort((x, y) => x - y);
  let results = [], len = nums.length - 1;

  while (true) {
    results.push(nums.slice());
    let i = len, j = len;
    // pos of shortest non-decreasing seq.
    while (i > 0) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
      i -= 1;
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
    } else
      break;

    // reverse rest of nums
    i = k;
    j = len;
    while (i < j) {
      let tmp = nums[i];
      nums[i++] = nums[j];
      nums[j--] = tmp;
    }
  }
  return results;
};