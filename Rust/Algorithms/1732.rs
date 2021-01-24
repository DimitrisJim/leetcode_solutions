impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let (mut max_height, mut height_i) = (0, 0);
        for i in gain {
            height_i += i;
            if height_i > max_height {
                max_height = height_i;
            }
        }
        max_height
    }
}
