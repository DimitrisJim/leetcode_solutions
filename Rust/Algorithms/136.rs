impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        // Zero like identity function for xor.
        nums.iter().fold(0, |acc, val| acc ^ val)
    }
}
