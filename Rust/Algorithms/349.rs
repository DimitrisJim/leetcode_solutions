use std::collections::HashSet;

impl Solution {
    pub fn intersection(n1: Vec<i32>, n2: Vec<i32>) -> Vec<i32> {
        let h1: HashSet<_> = n1.into_iter().collect();
        let h2: HashSet<_> = n2.into_iter().collect();

        h1.intersection(&h2).cloned().collect::<Vec<i32>>()
    }
}
