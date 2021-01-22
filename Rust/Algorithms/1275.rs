impl Solution {
    pub fn tictactoe(moves: Vec<Vec<i32>>) -> String {
        if (moves.len() < 5) {
            return String::from("Pending");
        }

        // Fill board up.
        let mut board = vec![vec![-1; 3], vec![-1; 3], vec![-1; 3]];
        let mut turn = 1;
        moves.iter().for_each(|v| {
            let (x, y) = (v[0] as usize, v[1] as usize);
            board[x][y] = turn;
            turn ^= 1;
        });

        // Find if any row/col/diag has a winner.
        for i in 0..3 {
            let r = &board[i];
            if (r[i] == -1) {
                continue;
            }
            if ((r[0] == r[1] && r[1] == r[2])
                || (board[0][i] == board[1][i]
                    && board[1][i] == board[2][i]))
            {
                return String::from(if r[i] == 1 { "A" } else { "B" });
            }
            // Only check once.
            if (i == 0) {
                let common = board[1][1];
                if (common == -1) {
                    continue;
                }
                if ((board[0][0] == common && common == board[2][2])
                    || (board[0][2] == common && common == board[2][0]))
                {
                    return String::from(if common == 1 {
                        "A"
                    } else {
                        "B"
                    });
                }
            }
        }
        // No winner, either Pending or Draw.
        String::from(if moves.len() < 9 { "Pending" } else { "Draw" })
    }
}
