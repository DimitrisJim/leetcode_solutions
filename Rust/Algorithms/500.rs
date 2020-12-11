use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    fn make_rows() -> Vec<HashSet<char>> {
        let mut rows = Vec::with_capacity(3);
        for &row in &["QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"] {
            rows.push(HashSet::from_iter(row.chars()));
        }
        return rows;
    }

    pub fn find_words(mut words: Vec<String>) -> Vec<String> {
        let rows = Solution::make_rows();
        let mut result = Vec::new();

        for word in words.iter_mut() {
            let wset = HashSet::from_iter(word.to_uppercase().chars());
            for set in rows.iter() {
                if wset.is_subset(&set) {
                    result.push(word.to_owned());
                }
            }
        }
        result
    }
}
