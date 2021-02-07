/**
 * @param {number[]} nums
 * @return {boolean}
 */
let check = nums => {
    const length = nums.length,
          start = nums[0];
    for (let i = 1; i < length; i++){
        // posible point of rotation
        if (nums[i-1] > nums[i]){
            for (let j=i+1; j < length; j++){
                // Make sure we still have non-decreasing order
                // and none are larger than start (which would
                // mean that before rotation, nums[i-1] < nums[i] for
                // nums[i-1] == start.)
                if (nums[j-1] > nums[j] || start < nums[j])
                    return false;
            }
        }
    }
    return true;    
};
