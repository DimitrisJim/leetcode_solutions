impl Solution {
    pub fn find_complement(N: i32) -> i32 {
        // Finds number of leading zeros.
        // See 5.3 hackers delight.
        // Don't know why they don't give us an u32
        // if num >= 1.
        let num = N as u32;
        if num == 0 {
            return 1;
        }
        let (mut n, mut x) = (0, num);
        if x <= 0x0000FFFF {
            n = n + 16;
            x = x << 16;
        }
        if x <= 0x00FFFFFF {
            n = n + 8;
            x <<= 8;
        }
        if x <= 0x0FFFFFFF {
            n = n + 4;
            x = x << 4;
        }
        if x <= 0x3FFFFFFF {
            n = n + 2;
            x = x << 2;
        }
        if x <= 0x7FFFFFFF {
            n = n + 1;
        }

        // Invert it and keep around one's
        (!num & 0xFFFFFFFF >> n) as i32
    }
}
