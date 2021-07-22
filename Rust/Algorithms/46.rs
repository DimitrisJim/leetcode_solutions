use std::mem::swap;

impl Solution {
    pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort_unstable();
        let mut results = Vec::new();
        let len = nums.len() - 1;

        loop {
            results.push(nums.clone());
            let (mut i, mut j) = (len, len);
            // pos of shortest non-decreasing seq.
            while i > 0 {
                if nums[i - 1] < nums[i] {
                    break;
                }
                i -= 1;
            }
            let mut k = 0;
            if i > 0 {
                // find smallest value > nums[i-1]
                while j >= i {
                    if nums[j] > nums[i - 1] {
                        break;
                    }
                    j -= 1;
                }
                // Switch i-1 with j
                nums.swap(i - 1, j);
                // reverse *after* i
                k = i;
            } else {
                break;
            }
            // reverse rest of nums
            let (mut i, mut j) = (k, len);
            while i < j {
                nums.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        results
    }
}
