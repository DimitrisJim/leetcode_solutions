/**
 * @param {number[]} nums
 * @return {number[]}
 */
let minSubsequence = nums => {
    let left_sum = nums.reduce((a, v) => a+=v), 
        seq = 0, 
        len = nums.length;
    nums.sort((a, b) => b - a);
    
    for (let i = 0; i < len; i++){
        let val = nums[i];
        left_sum -= val;
        seq += val;
        if ((seq - left_sum) > 0){
            return nums.slice(0, i+1);
        }
    }
};
