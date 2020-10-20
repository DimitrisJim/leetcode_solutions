use std::collections::HashSet;

impl Solution {
    pub fn num_jewels_in_stones(j: String, s: String) -> i32 {
        let h: HashSet<_> = j.chars().collect();
        let mut count = 0;
        for c in s.chars() {
            if h.contains(&c){
                count += 1;
            }
        }
        count
    }
}
