impl Solution {
    pub fn check_string(s: String) -> bool {
        let mut it = s.chars();
        while let Some(ch) = it.next() {
            if ch == 'b' {
                break;
            }
        }
        while let Some(ch) = it.next() {
            if ch == 'a' {
                return false;
            }
        }
        true
    }
}