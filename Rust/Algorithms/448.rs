impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut v = vec![0; nums.len()];
        for i in 1..=nums.len() {
            v[(nums[i - 1] - 1) as usize] = -1;
        }

        v.into_iter()
            .enumerate()
            .filter(|&(i, x)| x != -1)
            .map(|(i, x)| (i + 1) as i32)
            .collect()
    }
}
