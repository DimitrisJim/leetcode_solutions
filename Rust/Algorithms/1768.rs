impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let mut res = word1
            .chars()
            .zip(word2.chars())
            .flat_map(|pair| vec![pair.0, pair.1])
            .collect::<String>();

        // Push what's left from the largest.
        res.push_str(if word1.len() > word2.len() {
            &word1[word2.len()..]
        } else {
            &word2[word1.len()..]
        });
        res
    }
}
