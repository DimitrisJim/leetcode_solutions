impl Solution {
    pub fn projection_area(mut grid: Vec<Vec<i32>>) -> i32 {
        // Views for each dimension.
        let mut view_y = grid[0].clone();
        let mut view_z = view_y.iter().filter(|x| x.is_positive()).count();
        let mut view_x = *view_y
            .iter()
            .max()
            .expect("Empty cell shouldn't be possible.");

        for i in 1..grid.len() {
            let (mut count, mut max_v) = (0, 0);
            for (index, value) in (0..).zip(grid[i].iter()) {
                if *value > 0 {
                    // view_z
                    count += 1;
                    // view_x
                    if *value > max_v {
                        max_v = *value;
                    }
                    // view_y
                    if *value > view_y[index] {
                        view_y[index] = *value;
                    }
                }
            }
            // update counts:
            view_z += count;
            view_x += max_v;
        }
        // return their sum. (not sure why sum can't figure out type.)
        (view_z as i32) + view_x + view_y.iter().sum::<i32>()
    }
}
