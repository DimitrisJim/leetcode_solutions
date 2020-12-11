let countLargestGroup = n => {
    // Sort tuples reverse order.
    const revsorter = (x, y) => y[1] - x[1];
    
    // Build counter.
    let counts = new Map;
    for(let i = 1; i < n + 1; i++){
        let count = 0;
        for (let k of i+''){
            count += parseInt(k);
        }
        let group = counts.get(count);
        group ? counts.set(count, group+1) : counts.set(count, 1);
    }
    // Into array, sort, count groups of max values.
    counts = Array.from(counts.entries());
    counts.sort(revsorter);
    let count = 0,
        group = 0;
    for (let t of counts){
        if (group > 0){
            if (group != t[1]){
                return count;
            } 
            count++;
        } else {
            group = t[1];
            count = 1;
        }
    }
    return count;
};
