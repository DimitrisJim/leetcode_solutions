impl Solution {
    pub fn count_good_rectangles(rectangles: Vec<Vec<i32>>) -> i32 {
        let (mut max, mut count) = (0, 0);
        rectangles.into_iter().for_each(|v| {
            let (a, b) = (v[0], v[1]);
            let m = if a > b { b } else { a };
            if m == max {
                count += 1;
            } else if m > max {
                count = 1;
                max = m;
            }
        });
        count
    }
}
