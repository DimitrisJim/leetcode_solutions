impl Solution {
    pub fn common_factors(a: i32, b: i32) -> i32 {
        if a == 1 || b == 1 {
            return 1;
        }
        let mut fractions = 1;
        let (max, min) = if a > b { (a, b) } else { (b, a) };
        if max % min == 0 {
            fractions += 1;
        }

        for i in 2..((min / 2) + 1) {
            if max % i == 0 && min % i == 0 {
                fractions += 1;
            }
        }
        fractions
    }
}