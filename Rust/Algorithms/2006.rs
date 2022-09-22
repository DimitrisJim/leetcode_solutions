use std::collections::HashMap;

impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut counts = HashMap::new();
        
        for num in nums.iter() {
            counts.entry(num).and_modify(|count| *count += 1).or_insert(1);
        }
        
        let mut count = 0;
        for num in nums.iter() {
            let (a, b) = (num - k, num + k);
            if counts.contains_key(&a) {
                count += counts[&a];
            }
            if counts.contains_key(&b) {
                count += counts[&b];
            }
            if let Some(x) = counts.get_mut(&num) {
                *x -= 1;
            }
        }
        count
    }
}