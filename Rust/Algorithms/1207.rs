use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        // Create counts of elements.
        let mut counts = HashMap::new();
        for el in arr {
            match counts.get_mut(&el) {
                Some(v) => *v += 1,
                None => {
                    counts.insert(el, 1);
                }
            }
        }
        // If hashSet filters a count => we have a duplicate.
        counts.len() == counts.values().collect::<HashSet<_>>().len()
    }
}
