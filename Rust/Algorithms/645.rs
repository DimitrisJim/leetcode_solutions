impl Solution {
    pub fn find_error_nums(mut nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::with_capacity(2);
        for i in 0..nums.len() {
            let index = (nums[i].abs() - 1) as usize;
            if (nums[index] < 0) {
                res.push((index + 1) as i32);
                continue;
            }
            nums[index] = -nums[index];
        }

        for i in 0..nums.len() {
            if (nums[i] > 0) {
                res.push((i + 1) as i32);
                break;
            }
        }
        res
    }
}
