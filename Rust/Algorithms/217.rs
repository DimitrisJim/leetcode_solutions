use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut filter = HashSet::new();
        for i in nums.into_iter() {
            if filter.contains(&i) {
                return true;
            }
            filter.insert(i);
        }
        false
    }
}
