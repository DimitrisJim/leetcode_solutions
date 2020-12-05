class Solution:
    def numRookCaptures(self, board):
        row = col = 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    row, col = (i, j)
                    break   # no need to keep looking

        # always 'break' early.
        count = 0
        for i in range(col, 8):
            if board[row][i] == 'p':
                count += 1
                break
            if board[row][i] == 'B':
                break
        for i in range(col-1, -1, -1):
            if board[row][i] == 'p':
                count += 1
                break
            if board[row][i] == 'B':
                break
 
        for i in range(row, 8):
            if board[i][col] == 'p':
                count += 1
                break
            if board[i][col] == 'B':
                break
        for i in range(row, -1, -1):
            if board[i][col] == 'p':
                count += 1
                break
            if board[i][col] == 'B':
                break
        return count
