/**
 * @param {number[]} arr
 * @return {number[][]}
 */
let minimumAbsDifference = arr => {
    // Setup.
    let min_diff = 10 ** 6, result = [];
    const sorter = (x, y) => (x - y),
          abs = x => x < 0? -x: x,
          length = arr.length - 1;
    
    // Sort by numeric magnitude.
    arr.sort(sorter);
    
    // Go through pairs and find min diff.
    for(let k = 0; k < length; k++){
        let i = arr[k+1], j = arr[k];
        let diff = abs(i - j);
        if (diff < min_diff){
            min_diff = diff;
            result = [[j, i]];
        } else if (diff == min_diff){
            result.push([j, i]);
        }
    }
    return result;
};
