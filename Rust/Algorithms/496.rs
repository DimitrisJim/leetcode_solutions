use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn next_greater_element(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
    ) -> Vec<i32> {
        // Set up supporting structures.
        let nlen = nums1.len();
        let mut result = vec![-1; nlen];
        let mut seen = HashSet::new();
        let mut indices: HashMap<i32, usize> =
            nums1.into_iter().zip(0..nlen).collect();

        for i in nums2.into_iter() {
            // Must clone, can't reference immutably here and mutably with
            // seen.remove.
            for k in seen.clone().iter() {
                if i > *k {
                    result[*indices.get(k).unwrap()] = i;
                    seen.remove(k);
                }
            }
            if indices.contains_key(&i) {
                seen.insert(i);
            }
        }
        result
    }
}
