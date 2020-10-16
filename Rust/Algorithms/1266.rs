impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut steps = 0;
        let (mut diff_x, mut diff_y, mut abs_dx, mut abs_dy): (i32, i32, i32 ,i32);

        for i in 0..points.len() - 1{
            let (mut source_x, mut source_y) = (points[i][0], points[i][1]);
            let (dest_x, dest_y) = (points[i+1][0], points[i+1][1]);
            diff_x = dest_x - source_x;
            diff_y = dest_y - source_y;
            abs_dx = diff_x.abs();
            abs_dy = diff_y.abs();
            // Move horizontically.
            if (source_x != dest_x) || (source_y != dest_y){
                steps += if abs_dx < abs_dy{
                    source_x += diff_x;
                    source_y += if diff_y > 0 {
                        abs_dx
                    } else {
                        -abs_dx
                    };
                    abs_dx
                } else {
                    source_y += diff_y;
                    source_x += if diff_x > 0 {
                        abs_dy
                    } else {
                        -abs_dy
                    };
                    abs_dy
                }
            }
            diff_x = dest_x - source_x;
            abs_dx = diff_x.abs();
            // Move along the y-axis.
            steps += if (source_y != dest_y) && (source_x == dest_x){          
                diff_y = dest_y - source_y;
                abs_dy = diff_y.abs();  
                source_y += diff_y;
                abs_dy
            // Move along the x-axis.
            } else {
                diff_x = dest_x - source_x;
                abs_dx = diff_x.abs();
                source_x += diff_x;
                abs_dx
            };
        }
        steps
    }
}
