let getRow = n => {
    const result = [1],
          floor = Math.floor,
          round = Math.round;
    let fl = floor((n+1) / 2);
    let [mid, odd] = (n + 1) & 1 ? [fl + 1, true] : [fl, false];
        
    for (let k = 1; k < mid; k++) {
        let prev = result[k-1];
        result.push(round(prev * ((n + 1 - k) / k)));
    }
    // Note: reverse is in-place, need to slice *first*.
    return result.concat(odd? result.slice(0, -1).reverse() : result.slice().reverse());    
};
