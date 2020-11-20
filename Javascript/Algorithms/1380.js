/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
let luckyNumbers  = matrix => {
    // Initialize mins set, maxes list.
    let mins = new Set;
    let maxes = matrix[0];
    
    // Go through matrix and find mins/maxes.
    for (let row of matrix){
        let min_ = row[0];
        row.forEach((x, i) => {
            if (x < min_){
                min_ = x;
            }
            if (maxes[i] < x){
                maxes[i] = x;
            }
        })
        mins.add(min_);
    }

    // return intersection of mins, maxes:
    return maxes.filter((x) => mins.has(x));
};
