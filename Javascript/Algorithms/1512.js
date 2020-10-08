/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
    // sort (in-place)
    nums.sort()
    // 1 + 2 + 3 + ... + n
    let sn = (n) => (n * (n + 1)) / 2;
    let num_pairs = num = 0;
    for (i = 1; i < nums.length; i++){
        // add to count if same, calc pairs if not.
        if (nums[i] == nums[i-1]){
            num += 1;
        } else {
            num_pairs += sn(num);
            num = 0;
        }
    }
    // add leftover and return.
    return num_pairs + sn(num);
};
