use std::cmp::min;

impl Solution {
    pub fn get_min_distance(
        nums: Vec<i32>,
        target: i32,
        start: i32,
    ) -> i32 {
        let mut min_ = nums.len() as i32;
        for (index, i) in nums.into_iter().enumerate() {
            if i == target {
                min_ = min(min_, (start - (index as i32)).abs());
            }
        }
        min_
    }
}
