impl Solution {
    pub fn is_prefix_of_word(
        sentence: String,
        search_word: String,
    ) -> i32 {
        for (idx, str) in sentence.split(" ").enumerate() {
            if str.starts_with(&search_word) {
                return (idx + 1) as i32;
            }
        }
        -1
    }
}
