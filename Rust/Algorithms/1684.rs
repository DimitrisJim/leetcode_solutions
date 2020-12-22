use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn count_consistent_strings(
        allowed: String,
        words: Vec<String>,
    ) -> i32 {
        let al: HashSet<char> = allowed.chars().collect();
        words
            .into_iter()
            .filter(|x| x.chars().all(|c| al.contains(&c)))
            .count() as i32
    }
}
