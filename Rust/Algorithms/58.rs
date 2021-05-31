impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        // we deal with ascii strings.
        let b = s.as_bytes();
        let mut end = b.len();
        while b[end - 1] == 32 {
            end -= 1;
            if end == 0 {
                return 0;
            }
        }
        
        // reached end of string
        let mut count = 0;
        while end != 0 && b[end - 1] != 32 {
            end -= 1;
            count += 1;
        }
        count
    }
}