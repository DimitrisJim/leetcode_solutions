let mostVisited = (n, rounds) => {
    const length = rounds.length;
    let begin = [0, 0];
    
    // Check if we start from sector 1 or if we start
    // from some odd position. If so, keep track of where
    // we start (since these will contribute +1 to their)
    // visited count.
    let i = 0;
    if (rounds[i] != 1){
        let start = rounds[0];
        // find out if we perform a cycle around track.
        while (i < length - 1 && rounds[i] < rounds[i+1]){ i++; }
        // didn't cycle through track, return
        if (i == length - 1){
            let result = [];
            for(let i = start; i <= rounds[length-1]; i++){
                result.push(i);
            }
            return result;
        }
        // Else, keep around initial sectors ran.
        begin = [start, n];
    }
    // The final sectors ran (anything between will essentially be 
    // a cycle so +1 for everything.)
    const res = Array(n).fill(0),
		end = rounds[length-1];
        trail = end == n? [0, 0]: [1, rounds[length-1]];
    for (let [s, e] of [begin, trail]){
        if (s){
            for(let i = s; i <= e; i++){
                res[i-1]++;
            }
        }
    }

    // Find max and return elements with value == max.
    const m = res.reduce((acc, v) => acc > v? acc: v, 0), 
          r = [];
    res.forEach((v, idx) => {
        if (v == m) { 
            r.push(idx+1) 
        }  
    });
    return r;
};
