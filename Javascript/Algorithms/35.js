/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
let searchInsert = (nums, target) => {
  let start = 0, end = nums.length;
  while (start < end) {
    let mid = (start + end) >> 1;
    if (nums[mid] < target)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
};