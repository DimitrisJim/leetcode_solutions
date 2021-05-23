/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function(nums, target, start) {
  const min = Math.min, abs = Math.abs;
  let min_ = nums.length;
  nums.forEach((value, i) => {
    if (value == target) {
      min_ = min(min_, abs(start - i));
    }
  });
  return min_;
};