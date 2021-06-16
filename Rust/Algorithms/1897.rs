impl Solution {
    pub fn make_equal(words: Vec<String>) -> bool {
        // Build count of characters.
        let mut charCount = vec![0;26];
        for c in words.iter().flat_map(|s| s.as_bytes()).map(|cp| cp-97) {
            charCount[c as usize] += 1;
        }
        // Assert that we can distribute these evenly (char count % length == 0)
        for count in charCount {
            if count % words.len() > 0 {
                return false;
            }
        }
        true
    }
}