impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        sentences.iter().map(|sent| sent.split(' ').count()).max().unwrap() as i32
    }
}