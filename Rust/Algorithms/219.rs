use std::collections::HashMap;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        // nums => indices
        let mut indices = HashMap::<i32, usize>::new();
        for (i, v) in nums.into_iter().enumerate() {
            if let Some(iv) = indices.get(&v) {
                if i - iv > (k as usize) {
                    indices.insert(v, i);
                } else {
                    return true;
                }
            } else {
                indices.insert(v, i);
            }
        }
        false
    }
}