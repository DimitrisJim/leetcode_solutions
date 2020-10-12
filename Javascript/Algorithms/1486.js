/**
 * @param {number} n
 * @param {number} start
 * @return {number}
 */
var xorOperation = function(n, start) {
    let res = start;
    for(let i = 1; i < n; i++){
        res ^= start + 2 * i;
    }
    return res;
};
