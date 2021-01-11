impl Solution {
    #[inline]
    fn is_nozero(mut i: i32) -> bool {
        let mut d = 1000;
        while i < d {
            d /= 10;
        }
        while d > 0 {
            let q = i / d;
            if q == 0 {
                return false;
            }
            i %= d;
            d /= 10;
        }
        true
    }

    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        let is_nozero = Solution::is_nozero;
        let (mut upper, mut lower) = (n, 1);

        // break becomes return value.
        loop {
            let candidate = upper + lower;
            if candidate == n {
                break vec![lower, upper];
            } else if candidate < n {
                loop {
                    lower += 1;
                    if is_nozero(lower) {
                        break;
                    }
                }
            } else {
                loop {
                    upper -= 1;
                    if is_nozero(upper) {
                        break;
                    }
                }
            }
        }
    }
}
