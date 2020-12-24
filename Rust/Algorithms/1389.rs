impl Solution {
    pub fn create_target_array(
        nums: Vec<i32>,
        index: Vec<i32>,
    ) -> Vec<i32> {
        let mut target = Vec::with_capacity(nums.len());

        for (idx, value) in index.into_iter().zip(nums.into_iter()) {
            target.insert(idx as usize, value);
        }
        target
    }
}
