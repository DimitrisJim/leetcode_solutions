impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut index = 0;
        for c in s.chars() {
            match &t[index..].find(c) {
                Some(i) => index += i + 1,
                None => return false,
            }
        }
        true
    }
}
