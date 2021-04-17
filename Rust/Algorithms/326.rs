impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if (n & 1 == 0) || n <= 0 {
            return false;
        }
        let res = f64::log10(n as f64) / f64::log10(3 as f64);
        (res.round() - res).abs() < 1e-10
    }
}