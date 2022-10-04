impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let low = nums.partition_point(|&v| v < target) as i32;
        let high = nums.partition_point(|&v| v <= target) as i32;
        
        if low == high {
            vec![-1, -1]
        } else {
            vec![low, high - 1]
        }
    }
}