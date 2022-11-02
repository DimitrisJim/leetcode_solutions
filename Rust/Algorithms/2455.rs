impl Solution {
    pub fn average_value(nums: Vec<i32>) -> i32 {
        let (mut sum, mut count) = (0, 0);
        for val in nums {
            if val & 1 == 0 && val % 3 == 0 {
                sum += val;
                count += 1;
            }
        }
        if count == 0 {
            0
        } else {
            sum.div_euclid(count)
        }

    }
}