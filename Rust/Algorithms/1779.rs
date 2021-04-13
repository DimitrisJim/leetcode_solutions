impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let mut previous_min = 10 << 10;
        let mut index = -1;
        let mut dst = previous_min;
        for (i, p) in points.iter().enumerate() {
            let (xi, yi) = (p[0], p[1]);
            if xi == x {
                dst = yi - y;
            }
            if yi == y {
                dst = xi - x;
            }
            
            dst = dst.abs();
            if dst < previous_min {
                previous_min = dst;
                index = i as i32;
            }
        }
        index
    }
}