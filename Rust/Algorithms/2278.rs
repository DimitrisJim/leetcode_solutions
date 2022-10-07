impl Solution {
    pub fn percentage_letter(s: String, letter: char) -> i32 {
        let count = s.chars().filter(|&c| c == letter).count() as f64;
        ((count / s.len() as f64) * 100.) as i32
    }
}