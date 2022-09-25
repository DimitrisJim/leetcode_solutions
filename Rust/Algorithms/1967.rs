impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut count = 0;
        for pat in patterns {
            if word.contains(&pat) {
                count += 1;
            }
        }
        count
    }
}