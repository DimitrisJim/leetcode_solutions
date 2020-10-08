/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function(nums, n) {
    return nums.slice(0, n).flatMap((el, index) => [el, nums[n+index]])
};
