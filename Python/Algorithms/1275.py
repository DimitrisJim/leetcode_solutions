class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        # whatever moves, if len < 5, game is still pending.
        length = len(moves)
        if length < 5:
            return "Pending"
        
        # 1 -> 'A', 0 -> 'B'
        board, turn = [[-1] * 3 for _ in range(3)], 1
        for i, j in moves:
            # add to board and toggle turn.
            board[i][j], turn = turn, turn ^ 1

        for i in range(3):
            r = board[i]
            # board[i][i] is common element here, check
            # that it is not -1.
            if r[i] == -1:
                continue
            if r[0] == r[1] == r[2] or \
               board[0][i] == board[1][i] == board[2][i]:
                return 'A' if r[i] else 'B'
            if i == 0:
                common = board[1][1]
                # common != -1.
                if common == -1:
                    continue
                if board[0][0] == common == board[2][2] or \
                   board[0][2] == common == board[2][0]:
                    return 'A' if common else 'B'
        return "Pending" if length < 9 else "Draw"
