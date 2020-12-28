let shiftGrid = (grid, k) => {
    const rows = grid.length,
          cols = grid[0].length;
    // Find which row (k/cols) and which column (k % cols) shift beggins.
    let [d, r] = [Math.floor(k / cols), k % cols];
    // If we're outside # of rows, mod it.
    if (d >= rows){
        d = d % rows;
    }
    // No rotations to perform here.
    if (d == 0 && r == 0){
        return grid;
    }
    // Shift whole rows here.
    if (r == 0){
        let slice1 = grid.slice(rows - d, rows),
            slice2 = grid.slice(0, rows-d);
        
        return slice1.concat(slice2);
    }
    // No special cases, need to shift, flatten first:
    grid = grid.flat();
    const result = [],
          length = grid.length;
    
    // we start push into result from start until end
    // and then from 0 until start.
    let start = length - (d * cols + r),
        // count, sub help with filling sub-arrays.
        count = 0,
        sub = [],
        // Limits of looping to fill result, [start, length), [0, start].
        lims = [[start, length], [0, start+1]];  
    
    // Fill result grid.
    for(let [beg, end] of lims){
        for(let k = beg; k < end; k++){
            if (count == cols){
                result.push(sub);
                sub = [grid[k]];
                count = 1;
            } else {
                sub.push(grid[k]);
                count++;
            }
        }
    }   
    return result;
};
