impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut r = Vec::with_capacity(nums.len());
        for x in nums.iter().map(|&x| x as usize) {
            r.push(nums[x]);
        }
        r
    }
}