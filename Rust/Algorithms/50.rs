impl Solution {
    pub fn my_pow(mut x: f64, n: i32) -> f64 {
        if x == 0. || x == 1. {
            return x;
        }
        // flip sign of exponent.
        let mut pos_exp = true;
        let mut n = n as i64;
        if n < 0 {
            pos_exp = false;
            n = -n;
        }

        let mut result = 1.;
        while n > 0 {
            if n & 1 == 1 {
                result *= x;
            }
            x *= x;
            n /= 2;
        }
        // a ** (-b) => 1 / a ** b
        return if pos_exp { result } else { 1. / result };
    }
}
