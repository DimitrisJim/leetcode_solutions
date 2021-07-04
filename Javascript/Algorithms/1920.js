/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
  let r = [];
  nums.forEach(x => {
    r.push(nums[x]);
  });
  return r;
};