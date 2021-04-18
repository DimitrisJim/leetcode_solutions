impl Solution {
    fn to_digits(mut x: i32) -> Vec<i32> {
        let mut digits = Vec::with_capacity(10);
        while (x > 0){
            digits.push(x % 10);
            x = x / 10;
        }
        digits
    }
    
    pub fn reverse(x: i32) -> i32 {
        let bound: i32 = if x < 0 { -0x80000000 } else { 0x7FFFFFFF };
        // Handle edge case where x is equal to largest negative which
        // cannot be represented as positive.
        if (x < 0 && x == bound){
            return 0;
        }
        let x = x.abs();
        let x_digits = Solution::to_digits(x);

        if (x_digits.len() == 10){
            // If x has 10 digits, need to check we won't overflow. Build
            // digits array for bound
            let mut b_digits = Solution::to_digits(if bound < 0 { -(bound + 1) } else { bound });
            if (bound < 0){
                b_digits[0] += 1;
            }
            // And check that digits in x are smaller.
            for i in 0..10 {
                let (a, b) = (x_digits[i], b_digits[9-i]);
                if (a > b){
                    return 0;
                }
                if (a < b) {
                    break;
                }
            }
        }
        // Build result and return it.
        let mut res = 0;
        for (j, i) in (0..x_digits.len()).rev().enumerate() {
            res += x_digits[i] * (10_i32).pow(j as u32);
        }
        if bound < 0 { -res } else { res }
    }
}