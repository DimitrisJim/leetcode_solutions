impl Solution {
    pub fn reverse_bits(mut n: u32) -> u32 {
        let mut c = 1u32 << 31;
        let (mut rev, mut leading_zeros) = (0, 0);
        while n > 0 && n & c == 0 {
            leading_zeros += 1;
            c >>= 1;
        }
        while n != 0 {
            rev = (rev << 1) | (n & 1);
            n >>= 1;
        }
        rev << leading_zeros
    }
}