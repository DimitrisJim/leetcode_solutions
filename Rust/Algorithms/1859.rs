impl Solution {
    pub fn sort_sentence(s: String) -> String {
        let words: Vec<_> = s.split(" ").collect();
        let mut result = vec![String::from(""); words.len()];

        for w in words.into_iter() {
            let mut s = String::from(w);
            let pos =
                char::to_digit(s.pop().unwrap(), 10).unwrap() as usize;
            result[pos - 1] = s;
        }
        result.join(" ")
    }
}
