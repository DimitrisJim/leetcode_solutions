/**
 * @param {number[][]} moves
 * @return {string}
 */
let tictactoe = (moves) => {
    const length = moves.length;
    if (length < 5)
        return "Pending";
    
    // Fill board up.
    let board = [[-1, -1, -1], [-1, -1, -1], [-1, -1, -1]], turn = 1;
    moves.forEach(([x, y]) => {
        board[x][y] = turn;
        turn ^= 1;
    });
    
    // Find if any row/col/diag has a winner.
    for(let i = 0; i < 3; i++){
        let r = board[i];
        if (r[i] == -1)
            continue;
        if (
            (r[0] == r[1] && r[1] == r[2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        )
            return r[i] ? "A": "B";
        // Only check once.
        if (i == 0){
            let common = board[1][1];
            if (common == -1)
                continue;
            if ((board[0][0] == common && common == board[2][2]) ||
                (board[0][2] == common && common == board[2][0])
               )
                return common? "A" : "B";
        }
    }
    // No winner, either Pending or Draw.
    return length < 9 ? "Pending": "Draw";
};
