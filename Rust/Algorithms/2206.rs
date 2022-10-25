use std::collections::HashSet;

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let mut s = HashSet::new();
        
        for num in nums {
            if s.contains(&num) {
                s.remove(&num);
            } else {
                s.insert(num);
            }
        }
        s.len() == 0
    }
}