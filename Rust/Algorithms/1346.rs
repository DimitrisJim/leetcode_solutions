use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut nums = HashSet::with_capacity(arr.len());
        for num in arr.into_iter() {
            if nums.contains(&(num * 2)) {
                return true;
            }
            let half = (num as f32) / 2.;
            if half % 1. == 0. && nums.contains(&(half as i32)) {
                return true;
            }
            nums.insert(num);
        }
        return false;
    }
}
