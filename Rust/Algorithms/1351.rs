impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (grid.len(), grid[0].len());
        // Edge case: first element is < 0. Since array is 
        // sorted (row and column wise), all rest are < 0.
        if grid[0][0] < 0 {
            return (n * m) as i32;
        }
        // Edge case: only one row. Traverse row to find count.
        if n == 1{
            let mut positives = 0;
            while positives < m && grid[0][positives] >= 0 {
                positives += 1;
            }
            return (m - positives) as i32;
        }
        // Edge case: only one column. Traverse column to find count.
        if m == 1{
            let mut positives = 0;
            while positives < n && grid[positives][0] >= 0 {
                positives += 1;
            }
            return (n - positives) as i32;
        }
        
        // Starting points. Bottom right of grid and top left.
        // We count until these two points converge.
        let mut bottom_left = [n-1, 0];
        let mut top_right = [0, m-1];
        let mut negatives = 0;
        while bottom_left != top_right {
            let [bli, blj] = bottom_left;
            let [tri, trj] = top_right;
            
            // Additional edge cases while we count:
            // a) We've met on a row
            if bli == tri {
                // Count remaining negative numbers on row
                let mut j = blj;
                while j <= trj {
                    if grid[bli][j] < 0 {
                        negatives += 1;
                    }
                    j += 1;
                }
                return negatives;
            }
            // b) We've met on a column
            if blj == trj {
                let mut i = tri;
                while i <= bli {
                    if grid[i][trj] < 0 {
                        negatives += 1;
                    }
                    i += 1;
                }
                return negatives;
            }
            
            // Handle cases:
            // bottom_left point is negative
            if grid[bli][blj] < 0 {
                // If top right is also negative, count everything from
                // those points onwards. Remember to not double count.
                if grid[tri][trj] < 0 {
                    negatives += ((bli - tri) + (trj - blj) + 1) as i32;
                    // Adjust points, top_right column wise 
                    // and bottom_left row wise.
                    top_right[1] -= 1;
                    bottom_left[0] -= 1;
                // If it isn't, adjust it row wise.
                } else {
                    top_right[0] += 1;
                }
            // Need to adjust bottom_left column wise and 
            // top_right row wise.
            } else {
                // Similar check as before. If it is negative, we 
                // leave it as-is.
                if grid[tri][trj] >= 0 {
                    top_right[0] += 1;
                }
                bottom_left[1] += 1;
            }
            
        }
        // We've returned because bottom_left == top_right.
        // Check if the point we converged on is negative and 
        // then return.
        let [i, j] = bottom_left;
        match grid[i][j] < 0 {
            true => negatives + 1,
            false => negatives,
        }
    }
}
