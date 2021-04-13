impl Solution {
    pub fn truncate_sentence(mut s: String, mut k: i32) -> String {
        let mut new_len = s.len();
        for (i, c) in s.chars().enumerate() {
            if c == ' ' {
                k -= 1;
            }
            if k == 0 {
                new_len = i;
                break
            }
        }
        s.truncate(new_len);
        s
    }
}