impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        let mut res = Vec::new();
        for num in left..right+1 {
            // Count number of digits in num
            let (mut digits, mut temp) = (0, num);
            while temp != 0 {
                digits += 1;
                temp /= 10;
            }
            let mut div = (10_u32).pow(digits - 1) as i32;
            // Go through digits and count how many 
            // divide num
            let (mut count, mut red) = (0, num);
            while div != 0 {
                let d = red / div;
                red %= div;
                if d != 0 && num % d == 0 {
                    count += 1;
                } else {
                    break;
                }
                div /= 10;
            }
            // Equality means we've counted all digits.
            // Add it.
            if count == digits {
                res.push(num);
            }
        }
        
        res
    }
}
