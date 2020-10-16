int diagonalSum(int** mat, int matSize, int* matColSize){
    // Remove middle element if mat has odd length.
    int sum = matSize & 1 ? -mat[matSize >> 1][matSize >> 1] : 0;
    // Sum the diagonals.
    for(unsigned i = 0; i < matSize; i++){
        sum += mat[i][i] + mat[i][matSize - i - 1];
    }
    return sum;
}
