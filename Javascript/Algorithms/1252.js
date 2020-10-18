let oddCells = (n, m, indices) => {
    // Handle 1 x 1 case. (Basically #num of flips)
    if ((n == 1) && (m == 1)){
        return 0;
    }
    const cols = new Map;
    const rows = new Map;
    const len = indices.length
    let ni, mi;
    for(let i = 0; i < len; i++){
        ni = indices[i][0];
        mi = indices[i][1];
        if(rows.has(ni)){
            rows.delete(ni);
        } else {
            rows.set(ni, 1);
        }
        if(cols.has(mi)){
            cols.delete(mi);
        }else{
            cols.set(mi, 1);   
        }
    }
    const lc = cols.size
    const lr = rows.size
    // Handle edge cases 2 x 1 and 1 x 2
    if (((n == 1) && (m == 2)) || ((n == 2) && (m == 1))){
        return lr >= lc ? lr: lc;
    }
    // Handle edge case 2 x 2 matrix.
    if((n == 2) && (m == 2)){
        if (((lr == 2) && (lc == 2)) || ((lr == 0) && (lc == 0))){
            return 0;
        }else if (((lr == 0) && (lc == 2)) || ((lr == 2) && (lc == 0))){
            return 4;
        }
        return 2;
    }
    // Handle edge case where either m or n is 2.
    if ((n == 2) || (m == 2)){
        return n == 2? (m - lc) * lr : (n - lr) * lc;
    }
    // Sum according to # of odd rows/cols
    return (m - lc) * lr + (n - lr) * lc;
};
