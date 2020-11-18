/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    const len = A.length;
    for(let i = 0; i < len; i++){
        A[i] = A[i] * A[i];
    }
    A.sort((a, b) => a - b);
    return A;
};
