char *tictactoe(int **moves, int movesSize, int *movesColSize) {
  if (movesSize < 5)
    return "Pending";

  // Fill board up.
  int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}}, turn = 1;
  for (int i = 0; i < movesSize; i++) {
    int x = moves[i][0], y = moves[i][1];
    board[x][y] = turn;
    turn ^= 1;
  }

  for (int i = 0; i < 3; i++) {
    int *r = board[i];
    if (r[i] == -1)
      continue;
    if ((r[0] == r[1] && r[1] == r[2]) ||
        (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
      return r[i] ? "A" : "B";
    if (i == 0) {
      int common = board[1][1];
      if (common == -1)
        continue;
      if ((board[0][0] == common && common == board[2][2]) ||
          (board[0][2] == common && common == board[2][0]))
        return common ? "A" : "B";
    }
  }
  return movesSize < 9 ? "Pending" : "Draw";
}
