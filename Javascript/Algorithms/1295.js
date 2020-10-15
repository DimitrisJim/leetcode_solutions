/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let sum = 0;
    let len = nums.length
    for(let i=0; i < len; i++){
        let j = nums[i]
        if (
            ((9 < j) && (j < 100)) || 
            ((999 < j) && (j < 10000)) || 
            (j === 100000)
        )
            sum += 1;
    }
    return sum;
};
