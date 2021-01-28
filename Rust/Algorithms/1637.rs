use std::cmp::max;

impl Solution {
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        let mut r_points: Vec<_> = points.iter().map(|p| p[0]).collect();
        let mut max_ = 0;

        r_points.sort_unstable();
        for i in 0..r_points.len() - 1 {
            max_ = max(max_, r_points[i + 1] - r_points[i]);
        }
        max_
    }
}
