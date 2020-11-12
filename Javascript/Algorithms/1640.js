/**
 * @param {number[]} arr
 * @param {number[][]} pieces
 * @return {boolean}
 */
let canFormArray = (arr, pieces) => {
    const elems = new Set(arr);
    
    for (let el of pieces) {
        // For 1 element sub-arrays, we bail here.
        if (!elems.has(el[0])){
            return false;
        }
        let l = el.length;
        if (l > 1) {
            // For sub-arrays with length > 1, we check the 
            // elements to see if they match.
            let idx = arr.indexOf(el[0]);
            for(let j = 1; j < l; j++){
                let idx_ = idx + j;
                if ((idx_ >= arr.length) || (arr[idx_] != el[j])){
                    return false;
                }
            }
        }
    }
    return true;
};
