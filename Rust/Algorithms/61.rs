impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut mat = Vec::with_capacity(m);

        mat.push(vec![1; n]);
        for i in 1..m {
            mat.push(vec![0; n]);
        }
        for r in 1..m {
            for c in 0..n {
                mat[r][c] = mat[r - 1][c];
                if c > 0 {
                    mat[r][c] += mat[r][c - 1];
                }
            }
        }
        mat[m - 1][n - 1]
    }
}
