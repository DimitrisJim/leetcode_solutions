impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let s = s.as_bytes();
        let (mut start, mut end, mut diff) = (0, s.len()-1, 0);
        
        while start < end {
            if s[start] != s[end] {
                diff = 1;
                break;
            }
            start += 1;
            end -= 1;
        }
        if diff == 0 {
            return true;
        }
        let mut substr = &s[start+1..end+1];
        if substr.into_iter().eq(substr.into_iter().rev()) {
            return true;
        }
        substr = &s[start..end];
        if substr.into_iter().eq(substr.into_iter().rev()) {
            return true;
        }
        false
    }
<