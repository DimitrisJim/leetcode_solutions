use std::convert::TryFrom;

impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let mut max: f64 = -1.0;

        let len = points.len();
        let (imax, jmax, kmax) = (len - 3 + 1, len - 3 + 2, len);
        for i in 0..imax {
            for j in i + 1..jmax {
                for k in j + 1..kmax {
                    let (p1, p2, p3) =
                        (&points[i], &points[j], &points[k]);
                    let (x1, x2, x3) = (p1[0], p2[0], p3[0]);
                    let (y1, y2, y3) = (p1[1], p2[1], p3[1]);

                    let area = (0.5
                        * f64::try_from(
                            x1 * y2 + x2 * y3 + x3 * y1
                                - x2 * y1
                                - x3 * y2
                                - x1 * y3,
                        )
                        .unwrap())
                    .abs();
                    if area > max {
                        max = area;
                    }
                }
            }
        }
        max
    }
}
