var numRookCaptures = board => {
    let row = 0, col = 0;
    while (1){
        if (board[row][col] == 'R')
            break;
        if (row + 1 < 8)
            row++;
        else {
            row = 0;
            if (col + 1 < 8)
                col++;
            else 
                break;
        }
    }
    
    let count = 0;
    for (let i = col; i < 8; i++){
        if (board[row][i] == 'p') {
            count++;
            break;
        }
        if (board[row][i] == 'B') {
            break;
        }
    }
    for (let i = col-1; i >= 0; i--){
        if (board[row][i] == 'p') {
            count++;
            break;
        }
        if (board[row][i] == 'B') {
            break;
        }
    }

    for (let i = row; i < 8; i++){
        if (board[i][col] == 'p') {
            count++;
            break;
        }
        if (board[i][col] == 'B') {
            break;
        }
    }
    for (let i = row-1; i >= 0; i--){
        if (board[i][col] == 'p') {
            count++;
            break;
        }
        if (board[i][col] == 'B') {
            break;
        }
    }
    return count;    
};
