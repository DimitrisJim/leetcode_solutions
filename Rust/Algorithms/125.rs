impl Solution {
    pub fn is_palindrome(mut s: String) -> bool {
        s.make_ascii_uppercase();
        let s: String = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .collect();
        s.chars().eq(s.chars().rev())
    }
}