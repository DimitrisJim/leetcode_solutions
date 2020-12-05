int numRookCaptures(char **board, int boardSize, int *boardColSize) {
  int row = 0, col = 0;
  while (1) {
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

  int count = 0;
  for (int i = col; i < 8; i++) {
    if (board[row][i] == 'p') {
      count++;
      break;
    }
    if (board[row][i] == 'B') {
      break;
    }
  }
  for (int i = col - 1; i >= 0; i--) {
    if (board[row][i] == 'p') {
      count++;
      break;
    }
    if (board[row][i] == 'B') {
      break;
    }
  }

  for (int i = row; i < 8; i++) {
    if (board[i][col] == 'p') {
      count++;
      break;
    }
    if (board[i][col] == 'B') {
      break;
    }
  }
  for (int i = row - 1; i >= 0; i--) {
    if (board[i][col] == 'p') {
      count++;
      break;
    }
    if (board[i][col] == 'B') {
      break;
    }
  }
  return count;
}
