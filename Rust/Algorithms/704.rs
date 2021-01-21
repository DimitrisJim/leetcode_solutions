impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut start, mut end) = (0, nums.len() - 1);
        while start <= end {
            let idx = (start + end) / 2;
            let mid = nums[idx];
            if mid == target {
                return idx as i32;
            }
            // go left
            if target < mid {
                // Need to take care, usize wraps around.
                if idx == 0 {
                    return -1;
                }
                end = idx - 1;
            } else {
                start = idx + 1;
            }
        }
        -1
    }
}
