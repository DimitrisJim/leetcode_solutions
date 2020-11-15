/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let diff = x ^ y;
    let count = 0;
    while (diff){
        count += diff & 1;
        diff >>= 1;
    }
    return count;
};
