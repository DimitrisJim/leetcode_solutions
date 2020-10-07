/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let v = [];
    let running_sum = 0;
    for (let i of nums){
        running_sum += i;
        v.push(running_sum);
    }
    return v;
};
