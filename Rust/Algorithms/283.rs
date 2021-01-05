impl Solution {
    pub fn move_zeroes(mut nums: &mut Vec<i32>) {
        let (mut on_zero, mut run) = (0, 0);

        loop {
            while nums[on_zero] != 0 {
                on_zero += 1;
                if on_zero == nums.len() {
                    return;
                }
            }
            while nums[run] == 0 || run < on_zero {
                run += 1;
                if run == nums.len() {
                    return;
                }
            }
            let temp = nums[on_zero];
            nums[on_zero] = nums[run];
            nums[run] = temp;
        }
    }
}
