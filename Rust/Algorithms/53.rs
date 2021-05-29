use std::cmp::max;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut maximum = nums[0];
        let mut prev = 0;
        for num in nums {
            prev = max(num, prev + num);
            maximum = max(maximum, prev);
        }
        maximum
    }
}
