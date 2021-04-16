impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            false
        } else {
            let lg = f64::log2(n as f64);
            lg.ceil() == lg
        }
    }
}