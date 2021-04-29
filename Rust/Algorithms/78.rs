impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let size = 1 << nums.len();
        let mut result = Vec::with_capacity(size);
        result.push(vec![]);

        for i in 1..size {
            let mut sub = vec![];
            for j in 0..nums.len() {
                if (i & (1 << j)) != 0 {
                    sub.push(nums[j]);
                }
            }
            result.push(sub);
        }
        result
    }
}
