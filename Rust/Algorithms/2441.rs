impl Solution {
    pub fn find_max_k(mut nums: Vec<i32>) -> i32 {
        nums.sort_by_key(|k| k.abs());
        for i in (1..nums.len()).rev() {
            let (a, b) = (nums[i], nums[i-1]);
            if a + b == 0 {
                return a.abs();
            }
        }
        -1
    }
}