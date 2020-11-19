impl Solution {
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
        let mut left_sum: i32 = nums.iter().sum();
        let mut seq = 0;
        nums.sort_unstable_by(|a, b| b.cmp(a));
        // Find subsequence.
        for i in 0..nums.len() {
            left_sum -= nums[i];
            seq += nums[i];
            if (seq - left_sum) > 0 {
                // Could return here and use Vec::new at end of for loop
                // but meh.
                seq = (i as i32) + 1;
                break;
            }
        }
        // Return subsequence (thanks for the Vec return type tho.)
        (&nums[..seq as usize]).to_vec()
    }
}
