use std::collections::HashSet;

impl Solution {
    pub fn num_different_integers(word: String) -> i32 {
        word
            .split(char::is_alphabetic)
            .filter(|w| w.len() > 0)
            .map(|n| n.trim_start_matches('0'))
            .collect::<HashSet<_>>()
            .len() as i32
    }
}
