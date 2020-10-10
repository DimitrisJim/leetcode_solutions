use std::collections::HashMap;

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        // boilerplate set-up
        let mut seen = 0;
        let mut counts = HashMap::new();
        let mut sorted = nums.to_vec();
        sorted.sort_unstable();
        
        // build counts
        for val in &sorted {
            if (counts.contains_key(val)) {
                seen += 1;
            } else {
                counts.insert(val.clone(), seen);
                seen += 1;
            }
        }
        
        // re-use vec instead of creating new one.
        sorted.clear();
        for num in &nums {
            sorted.push(*counts.get(num).expect("The unexpected."));
        }
        
        return sorted
    }
}
