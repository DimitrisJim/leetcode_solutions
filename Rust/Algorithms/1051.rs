impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let length = heights.len();
        let mut target = Vec::with_capacity(length);
        let mut switches = 0;

        // We can be certain for the safety of this operation since
        // we've previously set the capacity to length.
        unsafe {
            target.set_len(length);
        }
        // Copy values of heights over and sort.
        target.copy_from_slice(&heights[..]);
        target.sort_unstable();

        // Count different positions
        for i in 0..length {
            if target[i] != heights[i] {
                switches += 1;
            }
        }
        switches
    }
}
