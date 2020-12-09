impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, K: i32) -> i32 {
        let (mut min, mut max) = (a[0], a[0]);
        for i in a {
            if i < min {
                min = i;
            }
            if i > max {
                max = i;
            }
        }
        let diff = max - K - min;
        if -K < diff && diff < K {
            return 0;
        }
        if diff > 0 {
            diff - K
        } else {
            diff + K
        }
    }
}
