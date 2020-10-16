impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let matlen = mat.len();
        let mut sum = if matlen & 1 == 1 {
            -mat[matlen >> 1][matlen >> 1]
        } else { 0 };
        for i in 0..matlen {
            sum += mat[i][i] + mat[i][matlen - i - 1];
        }
        sum        
    }
}
