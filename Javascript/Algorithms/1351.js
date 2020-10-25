/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    // Edge case: If first element is < 0 then, due to grid being 
    // sorted, we can return fast by counting all elements.
    const n = grid.length, m = grid[0].length;
    if (grid[0][0] < 0)
        return n * m;
    // Edge case: Single row, traverse it and count negatives.
    if (n == 1){
        let positives = 0;
        while((positives < m) && (grid[0][positives] >= 0)){
            positives++;
        }
        return m - positives;
    }
    // Edge case: Single column, traverse it and count negatives.
    if (m == 1){
        let positives = 0;
        while((positives < n) && (grid[positives][0] >= 0)){
            positives++;
        }
        return n - positives;        
    }
    
    // Starting points. Bottom left (bli, blj) of the grid and top right (tri, trj).
    // We count until these two points meet.
    let bli = n-1, blj = 0;
    let tri = 0, trj = m-1;
    let negatives = 0;
    while ((bli != tri) || (blj != trj)){
        // Additional cases while we move points:
        // a) We've met on a row:
        if (bli == tri){
            while (blj <= trj){
                if (grid[bli][blj] < 0) {
                    negatives++;
                }
                blj++;
            }
            return negatives;
        }
        // b) We've met on a column:
        if (blj == trj){
            while (tri <= bli) {
                if (grid[tri][trj] < 0){
                    negatives++;
                }
                tri++;
            }
            return negatives;
        }
        // Handle what we find on each point.
        // If bottom_left is negative:
        if (grid[bli][blj] < 0){
            // if top_right is also negative:
            if (grid[tri][trj] < 0){
                // Count negatives between two points 
                // also taking care to not double count.
                negatives += (bli - tri) + (trj - blj) + 1;
                // Adjust bottom_left row wise and top_right column wise.
                bli -= 1;
                trj -= 1;
            } else {
                // Adjust top_right row wise:
                tri += 1;
            }
        // Positive, adjust both if top_right is also positive.
        } else {
            if (grid[tri][trj] >= 0){
                tri += 1;
            }
            // Adjust bottom left column wise.
            blj += 1;
        }
    }
    // We've broken out of while, as such, we've converged on a single point.
    // Add it if it is negative.
    return negatives + (grid[bli][blj] < 0 ? 1 : 0);
};
