impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        // One distinct number, so, we can also xor in
        // all the numbers in the range and after xoring
        // with the numbers in nums, the unique element will
        // be the only one left (since it doesn't exist in
        // nums in order for it to be xore'd out.)
        let mut missing = 0;
        for i in 0..nums.len() {
            missing ^= ((i + 1) as i32) ^ nums[i];
        }
        missing
    }
}
