impl Solution {
    pub fn target_indices(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        nums.sort_unstable();
        nums.iter()
            .enumerate()
            .filter_map(|(idx, &val)| {
                if val == target {
                    Some(idx as i32)
                } else {
                    None
                }
            })
            .collect()
    }
}
