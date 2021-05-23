impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let mut n = matrix.len() - 1;
        let mut j = 0;
        let m = matrix[0].len();
        while j < m {
            let value = matrix[n][j];
            if (value == target) {
                return true;
            }
            if (value > target) {
                // usize, might wrap around.
                if n == 0 {
                    break;
                }
                n -= 1;
            } else {
                j += 1;
            }
        }
        false
    }
}
