use std::collections::HashSet;

impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut seen = HashSet::new();
        for ch in s.chars() {
            if !seen.insert(ch) {
                return ch;
            }
        }
        ' '
    }
}