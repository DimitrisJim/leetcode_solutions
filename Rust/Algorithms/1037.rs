impl Solution {
    #[inline]
    fn slope(p1: &Vec<i32>, p2: &Vec<i32>) -> f64 {
        let diff = f64::from(p2[1] - p1[1]);
        if p2[0] == p1[0] {
            return diff;
        }
        diff / f64::from(p2[0] - p1[0])
    }

    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        let [a, b, c] = [&points[0], &points[1], &points[2]];
        if (a[0] == b[0] && b[0] == c[0]) || (a[1] == b[1] && b[1] == c[1])
        {
            return false;
        }
        // a == b?
        if a[0] == b[0] && a[1] == b[1] {
            return false;
        }
        // a == c?
        if a[0] == c[0] && a[1] == c[1] {
            return false;
        }
        // b == c?
        if b[0] == c[0] && b[1] == c[1] {
            return false;
        }

        let slope = Solution::slope;
        let [s1, s2, s3] = [slope(a, b), slope(b, c), slope(a, c)];
        !(s1 == s2 && s2 == s3)
    }
}
