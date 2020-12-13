mpl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let (mut min, mut currently) = (1, 1);
        for i in nums {
            let diff = 1 - (currently + i);
            if diff > 0 {
                min += diff;
                currently += diff;
            }
            currently += i;
        }
        min
    }
}
