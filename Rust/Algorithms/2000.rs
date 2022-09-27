impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        if let Some(idx) = word.find(ch) {
            let (start, end) = word.split_at(idx + 1);
            let mut res: String = start.chars().rev().collect();
            res.push_str(end);
            res
        } else {
            word
        }
    }
}