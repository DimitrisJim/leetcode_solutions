impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        for k in 1..(1 << nums.len()) {
            let mut subtotal = 0;
            // View subsequences as bitstrings where bit set
            // indicates we should pick a specific index.
            // We essentially generate the following sequence:
            //
            // 0, 01, 10, 11, 001, 010, 100, 011, 101, 110, 111
            //
            // and use that to index into the array (via k & (1 << i))
            // which checks if the the i'th bit is set.
            for i in 0..nums.len() {
                if (k & (1 << i)) > 0 {
                    subtotal ^= nums[i];
                }
            }
            total += subtotal;
        }
        total
    }
}
