impl Solution {
    pub fn find_ocurrences(
        text: String,
        first: String,
        second: String,
    ) -> Vec<String> {
        let words: Vec<&str> = text.split(" ").collect();
        let mut result = Vec::new();
        let (mut start, limit) = (0, words.len() - 2);

        while start < limit {
            if words[start] == first {
                if words[start + 1] == second {
                    result.push(String::from(words[start + 2]));
                    start += 2;
                    continue;
                }
                start += 1;
                continue;
            }
            start += 1;
        }
        result
    }
}
