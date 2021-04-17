impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if ((n & 1 == 1) || n <= 0) && n != 1 {
            return false;
        }
        let res = f64::log10(n as f64) / f64::log10(4 as f64);
        (res.round() - res).abs() < 1e-10
    }
}