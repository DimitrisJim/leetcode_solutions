impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        for word in words {
            if word.chars().eq(word.chars().rev()) {
                return word
            }
        }
        String::new()
    }
}