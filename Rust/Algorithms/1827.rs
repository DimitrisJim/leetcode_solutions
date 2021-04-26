impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        if (nums.len() < 2) {
            return 0;
        }

        let mut inc = 0;
        for i in 1..nums.len() {
            let a = nums[i - 1];
            let b = &mut nums[i];
            if (a == *b) {
                inc += 1;
                *b += 1;
            } else if (a > *b) {
                let diff = (a - *b) + 1;
                inc += diff;
                *b += diff;
            }
        }
        inc
    }
}
