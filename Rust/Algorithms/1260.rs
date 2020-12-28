use std::collections::VecDeque;
use std::convert::TryFrom;

impl Solution {
    pub fn shift_grid(mut grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let (rows, cols) = (grid.len(), grid[0].len());
        // Create deque and rotate.
        let mut vq: VecDeque<_> = grid.into_iter().flatten().collect();
        vq.rotate_right((k as usize % (rows * cols)));

        // Fill result and return.
        let mut result = Vec::with_capacity(rows);
        for i in 0..rows {
            let mut inner = Vec::with_capacity(cols);
            for j in 0..cols {
                inner.push(vq.pop_front().unwrap());
            }
            result.push(inner);
        }
        result
    }
}
