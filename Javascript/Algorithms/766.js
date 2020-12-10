let isToeplitzMatrix = mat => {
    const cols = mat[0].length - 1,
          rows = mat.length - 1;
    for(let i = 0; i < rows; i++){
        for (let j = 0; j < cols; j++){
            if (mat[i][j] != mat[i+1][j+1]) {
                return false;
            }
        }
    }
    return true;    
};
