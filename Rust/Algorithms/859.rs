use std::iter::FromIterator;
use std::collections::HashSet;

impl Solution {
    pub fn buddy_strings(a: String, b: String) -> bool {
        if a.len() != b.len() {
            return false;
        }
        let diffs: Vec<usize> = a.chars()
            .zip(b.chars())
            .enumerate()
            .filter(|(i, (ai, bi))| ai != bi)
            .map(|(i, (_, _))| i)
            .collect();

        match diffs.len() {
            2 => {
                let (i, j) = (diffs[0], diffs[1]);
                // there must be a better way to do this, honestly.
                if a.chars().nth(i) == b.chars().nth(j) && 
                   a.chars().nth(j) == b.chars().nth(i) {
                    true
                } else {
                    false
                }
            },
            0 => {
                (HashSet::<char>::from_iter(a.chars()).len() < a.len()) &&
                (HashSet::<char>::from_iter(b.chars()).len() < b.len())
            },
            1 | _ => false,
        }
    }
}