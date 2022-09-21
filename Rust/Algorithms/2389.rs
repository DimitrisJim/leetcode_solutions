impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable();
        
        let mut acc = 0;
        for i in 0..nums.len() {
            nums[i] += acc;
            acc = nums[i];
        }
        
        let mut result = vec![0; queries.len()];
        for i in 0..queries.len() {
            result[i] = nums
                .binary_search(&queries[i])
                .map_or_else(|e| e, |o| o + 1) as i32;
        }
        result
    }
}