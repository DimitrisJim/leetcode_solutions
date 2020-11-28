/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 * };
 */

/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
let findSolution = (customfunction, z) => {
    let res = [],
        f = customfunction.f;
    for(let i = 1; i < 101; i++){
        for(let j = 1; j < 101; j++){
            let result = f(i, j);
            if (result == z){
                res.push([i, j]);
                break;
            }
            if (result > z){
                break;
            }
        }
    }
    return res;
};
