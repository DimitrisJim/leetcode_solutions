impl Solution {
    pub fn is_toeplitz_matrix(mat: Vec<Vec<i32>>) -> bool {
        let (rows, cols) = (mat.len() - 1, mat[0].len() - 1);
        for i in 0..rows {
            for j in 0..cols {
                if mat[i][j] != mat[i + 1][j + 1] {
                    return false;
                }
            }
        }
        true
    }
}
