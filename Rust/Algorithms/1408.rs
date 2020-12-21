impl Solution {
    pub fn string_matching(mut words: Vec<String>) -> Vec<String> {
        let length = words.len();
        let mut result = Vec::new();

        words.sort_unstable_by_key(|w| w.len());
        for (idx, word) in (1..length + 1).zip(words.iter()) {
            for i in idx..length {
                if words[i].contains(&word[..]) {
                    // Can't take since we iter, clone.
                    result.push((*word).clone());
                    break;
                }
            }
        }
        result
    }
}
