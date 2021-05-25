impl Solution {
    const LIMITS: [i64; 9] = [
        9, 189, 2889, 38889, 488889, 5888889,
        68888889, 788888889, 8888888889
    ];

    pub fn find_nth_digit(n: i32) -> i32 {
        if (n < 10){
            return n;
        }
        let n = n as i64;
        let limits = Solution::LIMITS;
        let mut i = 0;
        while (n > limits[i]) {
            i += 1;
        }

        // need the largest value smaller than n.
        let digits_left = n - (limits[i-1] + 1);
        // i == 0 => 1 digits. i == 1 => 2 digits..
        let pos = digits_left / (i as i64 + 1);
        let digit = digits_left % (i as i64 + 1);
        
        // While loop would be so much better but I wanted
        // to check out how easy this would be. (and rust doesn't make it easy.)
        i32::from_str_radix(
            &((10i64).pow(i as u32) + pos)
                .to_string()
                .chars()
                .skip(digit as usize)
                .next().unwrap()
                .to_string()[..],
            10
        ).unwrap()
    }
}  