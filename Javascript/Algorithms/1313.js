/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    let a = [];
    for(i = 0; i < nums.length;){
        for(j = 0; j < nums[i]; j++)
            a.push(nums[i+1]);
        i += 2;
    }
    return a;
};
