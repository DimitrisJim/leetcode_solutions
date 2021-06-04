impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let mut seq_len = 1;
        let mut max_len = 1;
        let mut prev = nums[0];
        for n in nums {
            if (n > prev) {
                seq_len += 1;
                if (seq_len > max_len) {
                    max_len = seq_len;
                }
            } else {
                seq_len = 1;
            }
            prev = n;
        }
        max_len
    }
}
