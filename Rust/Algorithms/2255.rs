impl Solution {
    pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
        let s = s.as_str();
        words
            .iter()
            .filter(|w| s.starts_with(w.as_str()))
            .collect::<Vec<_>>()
            .len() as i32
    }
}