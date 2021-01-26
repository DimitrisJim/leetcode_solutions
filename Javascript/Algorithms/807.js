ram {number[][]} grid
 * @return {number}
 */
let maxIncreaseKeepingSkyline = grid => {
    let rows = grid.length, cols = grid[0].length;
    const max_cols = [];
    
    let max_increase = 0;
    for (let i = 0; i < rows; i++){
        // find max row for this row to use.
        let row = grid[i],
            max_row = -1;
        for (let j = 0; j < cols; j++){
            let v = row[j];
            if (v > max_row)
                max_row = v;
        }
        for (let j = 0; j < cols; j++){
            if (j == max_cols.length){
                // find max column value.
                let max_col = -1;
                for(let i = 0; i < rows; i++)
                {
                    let v = grid[i][j];
                    if (v > max_col)
                        max_col = v;
                }
                max_cols[j] = max_col;
            }
            let value = grid[i][j];
            // diff is the difference between min of maxes minus value.
            let diff = max_row < max_cols[j] ? max_row - value: max_cols[j] - value;
            if (diff > 0){
                max_increase += diff;
            }
        }
    }
    return max_increase;
};
