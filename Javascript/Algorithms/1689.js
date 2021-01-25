/**
 * @param {string} n
 * @return {number}
 */
let minPartitions = n => {
    let max = n[0];
    for (let c of n){
        if (c > max)
            max = c;
    }
    // '0' -> 48
    return max.codePointAt() - 48;
};
