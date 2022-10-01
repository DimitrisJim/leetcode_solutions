impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        let pref = pref.as_str();
        words
            .iter()
            .filter(|w| w.starts_with(pref))
            .collect::<Vec<_>>()
            .len() as i32
    }
}
