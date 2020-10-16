/**
 * @param {number[][]} mat
 * @return {number}
 */
let diagonalSum = mat => {
    const len = mat.length
    let s = len % 2 ? -mat[len>>1][len>>1] : 0;
    for(let i = 0; i < len; i++)
        s = s + mat[i][i] + mat[i][len - i - 1];
    return s;
};
