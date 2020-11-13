use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        let mut ret: i32 = 0;
        for i in a.iter() {
            if seen.contains(&i) {
                return *i;
            }
            seen.insert(i);
        }
        // Can't expect rust to know we always return in the loop.
        0
    }
}
