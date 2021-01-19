// See:
// https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself
let generate = numRows => {
    const result = [],
          round = Math.round,
          floor = Math.floor;
    for (let n = 0; n < numRows; n++) {
        let inner = [1];
        let fl = floor((n+1) / 2);
        let [mid, odd] = (n + 1) & 1 ? [fl + 1, true] : [fl, false];
        
        for (let k = 1; k < mid; k++) {
            let prev = inner[k-1];
            inner.push(round(prev * ((n + 1 - k) / k)));
        }
        result.push(
            // Note: reverse is in-place, need to slice *first*.
            inner.concat(odd? inner.slice(0, -1).reverse() : inner.slice().reverse())
        );
    }
    return result;
};
