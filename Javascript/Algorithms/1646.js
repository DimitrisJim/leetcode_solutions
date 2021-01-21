/**
 * @param {number} n
 * @return {number}
 */
let getMaximumGenerated = n => {
    if (n < 2)
        return n;
    
    const A = Array(n+1).fill(0),
          floor = Math.floor;
    A[1] = 1;
    
    let max = 0;
    for (let i = 2; i <= n; i++){
        let q = floor(i / 2), r = i % 2,
            val = A[q];
        if (val > max)
            max = val;
        if (r){
            let add = val + A[q+1];
            if (add > max)
                max = add;
            A[i] = add;
        } else {
            A[i] = val;
        }
    }
    return max;    
};
