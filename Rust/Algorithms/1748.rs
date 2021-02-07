use std::collections::HashSet;

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let (mut seen, mut unique) = (HashSet::new(), HashSet::new());

        for num in nums {
            if seen.contains(&num) {
                if unique.contains(&num) {
                    unique.remove(&num);
                }
            } else {
                seen.insert(num);
                unique.insert(num);
            }
        }
        unique.into_iter().sum::<i32>()
    }
}
