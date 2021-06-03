impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        // Build a count of letters (note, need extra space because some 
        // non-letter chars follow uppercase ones.)
        let mut letters = vec![0; 58];
        for c in s.as_bytes() {
            letters[(*c - 65) as usize] += 1;
        }

        let mut length = 0;
        let mut add = 0;
        for count in letters {
            if count & 1 == 1 {
                add = 1;
                length -= 1;
            }
            length += count;
        };
        length + add
    }
}