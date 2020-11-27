// This is damn pretty. 
impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        word1
            .iter()
            .flat_map(|s| s.chars())
            .eq(word2.iter().flat_map(|s| s.chars()))
    }
}
