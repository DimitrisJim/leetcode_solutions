ram {number[][]} A
 * @return {number[][]}
 */
let transpose = A => {
    const columns = A[0].length,
          rows = A.length,
          result = [];
    
    for (let i = 0; i < columns; i++){
        let sub = [];
        for (let j = 0; j < rows; j++){
            sub.push(A[j][i]);
        }
        result.push(sub);
    }
    return result;
};
