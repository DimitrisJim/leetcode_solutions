use std::cmp::min;

impl Solution {
    pub fn min_time_to_type(word: String) -> i32 {
        let mut prev = 97;
        let mut result = word.len() as i32;
        for (&c) in word.as_bytes() {
            let dst = if prev > c { prev - c } else { c - prev };
            result += min(dst, 26 - dst) as i32;
            prev = c;
        }
        result
    }
}
