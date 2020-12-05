impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let (mut row, mut col) = (0, 0);
        for i in 0..8 {
            for j in 0..8 {
                match board[i][j] {
                    'R' => {
                        row = i;
                        col = j;
                    }
                    _ => {}
                }
            }
        }

        let mut count = 0;
        // Look through the row where Rook is.
        for i in col..8 {
            if board[row][i] == 'p' {
                count += 1;
                break;
            }
            if board[row][i] == 'B' {
                break;
            }
        }
        for i in (0..col).rev() {
            if board[row][i] == 'p' {
                count += 1;
                break;
            }
            if board[row][i] == 'B' {
                break;
            }
        }

        // Look through the column where Rook is.
        for i in row..8 {
            if board[i][col] == 'p' {
                count += 1;
                break;
            }
            if board[i][col] == 'B' {
                break;
            }
        }
        for i in (0..row).rev() {
            if board[i][col] == 'p' {
                count += 1;
                break;
            }
            if board[i][col] == 'B' {
                break;
            }
        }
        count
    }
}
