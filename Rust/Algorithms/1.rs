use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();

        let (mut id1, mut id2) = (0i32, 0i32);
        for i in 0..nums.len() {
            let x = nums[i];
            if let Some(&v) = seen.get(&(target - x)) {
                id1 = i as i32;
                id2 = v as i32;
            }
            seen.insert(x, i);
        }
        vec![id1, id2]
    }
}
