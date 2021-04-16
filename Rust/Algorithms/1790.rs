use std::iter::FromIterator;
use std::collections::HashSet;

impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        // More than two positions differ -> can't swap.
        if s1.chars().zip(s2.chars()).filter(|(a, b)| a != b).count() > 2 {
            return false;
        }
        // Compare sets created from Strings.
        HashSet::<char>::from_iter(s1.chars()) == HashSet::<char>::from_iter(s2.chars())
    }
}