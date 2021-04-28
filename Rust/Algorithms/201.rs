impl Solution {
    pub fn range_bitwise_and(left: i32, right: i32) -> i32 {
        let bit_length = |mut n| {
            let mut count = 0;
            while (n > 0) {
                count += 1;
                n /= 2;
            }
            return count;
        };

        if left == right {
            return left;
        }

        // First property: diff bit lengths => zero.
        let bits = bit_length(left);
        if bits < bit_length(right) {
            return 0;
        }
        // Second property: result == largest common bit prefix of left+right.
        let mut result = 1 << (bits - 1);
        let mut mask = 1 << (bits - 2);
        while mask > 0 {
            if ((mask & left) == (mask & right)) {
                result |= (mask & left);
            } else {
                break;
            }
            mask >>= 1;
        }
        result
    }
}
