impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (rows, cols) = (mat.len() - 1, mat[0].len() - 1);
        let mut diag = vec![];

        let (mut r, mut c) = (rows, 0);
        while r != 0 || c != cols {
            // Grab diagonal in diag.
            let (mut i, mut j) = (r, c);
            while i <= rows && j <= cols {
                diag.push(mat[i][j]);
                i += 1;
                j += 1;
            }
            // Sort it (reversed)
            diag.sort_unstable();
            diag = diag.into_iter().rev().collect();

            // And add it back to mat.
            i = r;
            j = c;
            while i <= rows && j <= cols {
                mat[i][j] = diag.pop().unwrap();
                i += 1;
                j += 1;
            }
            if r == 0 {
                c += 1;
            }
            if r > 0 {
                r -= 1;
            }
        }
        mat
    }
}
