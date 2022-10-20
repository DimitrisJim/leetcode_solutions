use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn find_final_value(nums: Vec<i32>, mut original: i32) -> i32 {
        let s: HashSet<i32> = nums.into_iter().collect();
        while s.contains(&original) {
            original *= 2;            
        }
        original
    }
}