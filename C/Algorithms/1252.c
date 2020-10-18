int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    // Handle 1 x 1 case. (Basically #num of flips)
    if ((n == 1) && (m == 1)){
        return 0;
    }
    
    // Need 64 bits at least.
    long long rows = 0, cols = 0;
    // Fill in rows/columns
    for(int i = 0; i < indicesSize; i++){
        rows ^= (1ll << indices[i][0]);
        cols ^= (1ll << indices[i][1]);
    }
    // Count bits set:
    int lr = 0, lc = 0;
    for(; rows > 0; rows >>= 1)
        lr += rows & 1; 
    for(; cols > 0; cols >>= 1)
        lc += cols & 1;
    
    // Handle edge cases 2 x 1 and 1 x 2
    if (((n == 1) && (m == 2)) || ((n == 2) && (m == 1))){
        return lr >= lc ? lr: lc;
    }
    // Handle edge case 2 x 2 matrix.
    if((n == 2) && (m == 2)){
        if (((lr == 2) && (lc == 2)) || ((lr == 0) && (lc == 0))){
            return 0;
        }else if (((lr == 0) && (lc == 2)) || ((lr == 2) && (lc == 0))){
            return 4;
        }
        return 2;
    }
    // Handle edge case where either m or n is 2.
    if ((n == 2) || (m == 2)){
        return n == 2? (m - lc) * lr : (n - lr) * lc;
    }
    // Sum according to # of odd rows/cols
    return (m - lc) * lr + (n - lr) * lc;
}
