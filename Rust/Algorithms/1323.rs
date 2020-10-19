impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        let (mut digits, mut temp) = (0, num);
        // Count number of digits (+ 1)
        while temp != 0 {
            digits += 1;
            temp /= 10;
        }
        // Find appropriate 10-multiple of 9.
        let mut d: i32 = 9 * (10 as i32).pow(digits-1);
        let (mut div, mut t) = (num / d, num % d);

        // Calculate number.
        while div == 1 {
            d /= 10;
            if d == 0 {
                return num;
            }
            div = t / d;
            t %= d;
        }
        num + (d / 3)
    }
}
