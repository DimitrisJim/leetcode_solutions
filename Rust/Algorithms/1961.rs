impl Solution {
    pub fn is_prefix_string(s: String, words: Vec<String>) -> bool {
        let mut s = s.as_str();
        for word in words {
            if !s.starts_with(word.as_str()) {
                break;
            }
            s = &s[word.len()..];
        }
        s == ""
    }
}