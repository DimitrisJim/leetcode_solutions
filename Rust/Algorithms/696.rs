impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let (mut c_ones, mut c_zeros, mut count) = (0, 0, 0);
        let (mut clear_on_next_zero, mut clear_on_next_one) =
            (false, false);
        for c in s.chars() {
            if (c == '0') {
                if (clear_on_next_zero) {
                    clear_on_next_zero = false;
                    c_zeros = 0;
                }
                c_zeros += 1;
                // we have seen ones
                if (c_ones > 0) {
                    if (c_zeros <= c_ones) {
                        count += 1;
                    }
                    clear_on_next_one = true;
                }
            } else {
                if (clear_on_next_one) {
                    clear_on_next_one = false;
                    c_ones = 0;
                }
                c_ones += 1;
                // we have seen ones
                if (c_zeros > 0) {
                    if (c_ones <= c_zeros) {
                        count += 1;
                    }
                    clear_on_next_zero = true;
                }
            }
        }
        count
    }
}
