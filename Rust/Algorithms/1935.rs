use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn can_be_typed_words(
        text: String,
        broken_letters: String,
    ) -> i32 {
        let s: HashSet<char> = HashSet::from_iter(broken_letters.chars());
        let mut count = 0;

        for w in text.split(' ') {
            for c in w.chars() {
                if s.contains(&c) {
                    count -= 1;
                    break;
                }
            }
            count += 1;
        }
        count
    }
}
