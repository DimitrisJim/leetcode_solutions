/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
let diagonalSort = mat => {
    const rows = mat.length - 1, cols = mat[0].length - 1,
          diag = [],
          sorter = (a, b) => b - a;
    
    let r = rows, c = 0;
    while (r != 0 || c != cols){
        let i = r, j = c;
        while (i <= rows && j <= cols)
            diag.push(mat[i++][j++]);
        
        diag.sort(sorter);
        i = r, j = c;
        while (i <= rows && j <= cols)
            mat[i++][j++] = diag.pop();
        
        if (r == 0) c++;
        if (r > 0) r --;
    }
    return mat;
};
