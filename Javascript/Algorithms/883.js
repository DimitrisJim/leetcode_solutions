/**
 * @param {number[][]} grid
 * @return {number}
 */
let projectionArea = (grid) => {
    // views for dimensions
    let view_y = grid[0],
        view_z = 0,
        view_x = 0;
    
    // yes, we go through grid[0] twice.
    grid.forEach(row => {
        let count = 0,
            max_value = 0;
        row.forEach((v, index) => {
            if (v > 0){
                // For view_z
                count++;
                // For view_x
                if (v > max_value){
                    max_value = v;
                }
                // Update view_y
                if (v > view_y[index]){
                    view_y[index] = v;
                }
            }
        });
        // Update counters.
        view_z += count;
        view_x += max_value;
    });
    
    // Add values together.
    return view_z + view_x + view_y.reduce((acc, val) => acc + val);;    
};
