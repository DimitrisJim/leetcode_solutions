impl Solution {
    pub fn has_alternating_bits(mut n: i32) -> bool {
        while n > 0 {
            let b = n & 1;
            n >>= 1;
            if b == n & 1 {
                return false;
            }
        }
        true
    }
}
