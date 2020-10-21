/**
 * @param {number[][]} A
 * @return {number[][]}
 */
let flipAndInvertImage = A => {
    return A.map(x => x.map(y => y ^ 1).reverse());
};
