let maxLengthBetweenEqualCharacters = s => {
    const d = new Map,
          length = s.length;
    // Build distances.
    for(let i = 0; i < length; i++){
        let c = s[i];
        if (!d.has(c)){
            d.set(c, [i, i]);
        } else {
            let lst = d.get(c);
            if (i > lst[1]){
                lst[1] = i;
                d.set(c, lst);
            }
        }
    }
    // and then find max.
    let max_diff = -1;
    for ([min, max] of d.values()){
        if (min != max){
            let diff = max - min - 1;
            if (diff > max_diff){
                max_diff = diff;
            }
        }
    }
    return max_diff;
};
