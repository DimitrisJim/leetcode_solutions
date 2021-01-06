impl Solution {
    pub fn is_monotonic(A: Vec<i32>) -> bool {
        let mut decreasing = -1;

        for i in 0..A.len() - 1 {
            let (a, b) = (A[i], A[i + 1]);
            if a != b {
                if decreasing == -1 {
                    decreasing = (a > b) as i32;
                    continue;
                }
                if (a > b) as i32 != decreasing {
                    return false;
                }
            }
        }
        true
    }
}
