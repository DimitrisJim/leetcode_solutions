/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
    let inter = []
    const reducer = (accumulator, currentValue) => accumulator + currentValue;
    mat.forEach((el, idx) => inter.push([idx, el.reduce(reducer)]));
    inter.sort((x, y) => x[1] - y[1]);
    return inter.slice(0, k).map(x => x[0]);
};
