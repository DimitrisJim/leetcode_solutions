/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    let len = nums.length, sum=0;
    // Thanks for default converting into strings.
    nums.sort((a, b) => a - b)
    while(len--){
        sum += nums[--len];
    }
    return sum;
};
