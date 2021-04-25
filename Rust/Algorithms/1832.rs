use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        HashSet::<char>::from_iter(sentence.chars()).len() == 26
    }
}
