/**
 * @param {string} S
 * @param {character} C
 * @return {number[]}
 */
let shortestToChar = (S, C) => {
    const result = [],
        length = S.length,
        floor = Math.floor;
    let prev_pos = -1;
          
    for (let pos=0; pos < length; pos++){
        if (S[pos] == C){
            if (prev_pos == -1){
                // Add distances from pos until 0.
                for(let i = pos; i >= 0; i--)
                    result.push(i); 
            } else {
                let diff = pos - prev_pos;
                let middle = floor(diff / 2);
                for(let i = 1; i < middle + (diff % 2) ? 1: 0; i++)
                    result.push(i);
                for(let i = middle; i >= 0; i--)
                    result.push(i);
            }
            prev_pos = pos;
        }
    }
    if (prev_pos != length){
        let diff = length - prev_pos;
        for(let i = 1; i < diff; i++)
            result.push(i);
    }
    return result;
};
