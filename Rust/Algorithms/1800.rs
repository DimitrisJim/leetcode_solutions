use std::cmp::max;

impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        if (nums.len() == 1) {
            return nums[0];
        }

        // Keep track of current sum and max found so far.
        let (mut current_sum, mut max_found) = (0, 0);
        for i in 0..nums.len() - 1 {
            let (a, b) = (nums[i], nums[i + 1]);
            current_sum += a;
            if (b <= a){
                // update max if current exceeds it.
                if (current_sum > max_found){
                    max_found = current_sum;
                }
                current_sum = 0;
            }
        }

        // Check final value. Either it contributes to current or
        // it is the final value to compare to max_found.
        let end = nums[nums.len() - 1];
        if (end > nums[nums.len() - 2]){
            current_sum += end;
            max(max_found, current_sum)
        } else {
            max(max_found, end)
        }
    }
}