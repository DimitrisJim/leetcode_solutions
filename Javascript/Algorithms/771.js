/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
let numJewelsInStones = (J, S) => {
    const h = new Set(J);
    let count = 0;
    for (let c of S){
        if (h.has(c)){
            count += 1;
        }
    }
    return count;
}; 
