impl Solution {
    pub fn smallest_equal(nums: Vec<i32>) -> i32 {
        for i in 0..nums.len() {
            if i % 10 == (nums[i] as usize) {
                return i as i32;
            }
        }
        -1
    }
}