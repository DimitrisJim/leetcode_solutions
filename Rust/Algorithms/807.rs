impl Solution {
    pub fn max_increase_keeping_skyline(grid: Vec<Vec<i32>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut max_cols = vec![];
        let mut max_increase = 0;
        for i in 0..rows {
            // get maximum of row.
            let max_row = grid[i].iter().max().unwrap();
            for j in 0..cols {
                if j == max_cols.len() {
                    // get maximum of column.
                    let mut max_col = -1;
                    for i in 0..rows {
                        if grid[i][j] > max_col {
                            max_col = grid[i][j];
                        }
                    }
                    max_cols.push(max_col);
                }
                // min of (max_row, max_col[j]) is max growth.
                // if diff > 0 we can grow diff ammount.
                let diff = max_row.min(&max_cols[j]) - grid[i][j];
                if diff > 0 {
                    max_increase += diff;
                }
            }
        }
        max_increase
    }
}
