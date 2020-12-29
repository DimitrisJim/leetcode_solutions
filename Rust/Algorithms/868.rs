impl Solution {
    pub fn binary_gap(mut n: i32) -> i32 {
        if n <= 2 {
            return 0;
        }
        let (mut max_dst, mut count, mut start) = (0, 0, false);
        while n > 0 {
            if n & 1 == 1 {
                if count >= max_dst {
                    max_dst = count;
                }
                count = 1;
                start = true;
            } else {
                if start {
                    count += 1;
                }
            }
            n >>= 1;
        }
        max_dst
    }
}
