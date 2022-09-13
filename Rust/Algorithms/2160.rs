impl Solution {
    pub fn minimum_sum(mut num: i32) -> i32 {
        let mut nums = vec![0;4];
        let mut d = 1000;
        
        for i in 0..=3 {
            nums[i] = num / d;
            num %= d;
            d /= 10;
        }
        nums.sort();

        (nums[0]*10 + nums[2]) + (nums[1] * 10 + nums[3])
    }
}