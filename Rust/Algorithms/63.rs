impl Solution {
    pub fn unique_paths_with_obstacles(
        obstacle_grid: Vec<Vec<i32>>,
    ) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();

        if obstacle_grid[0][0] == 1 || obstacle_grid[m - 1][n - 1] == 1 {
            return 0;
        }
        let mut mat = Vec::with_capacity(m);
        for i in 0..m {
            mat.push(vec![0; n]);
        }
        mat[0][0] = 1;
        for r in 0..m {
            for c in 0..n {
                if obstacle_grid[r][c] == 1 {
                    continue;
                }
                if r > 0 && obstacle_grid[r - 1][c] == 0 {
                    mat[r][c] = mat[r - 1][c];
                }
                if c > 0 && obstacle_grid[r][c - 1] == 0 {
                    mat[r][c] += mat[r][c - 1];
                }
            }
        }
        mat[m - 1][n - 1]
    }
}
