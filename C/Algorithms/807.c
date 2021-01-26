#include <stdlib.h>

int maxIncreaseKeepingSkyline(int **grid, int gridSize, int *gridColSize) {
  int rows = gridSize, cols = *gridColSize, mxcolsLen = 0;
  int *max_cols = malloc(cols * sizeof(*max_cols));

  int max_increase = 0;
  for (int i = 0; i < rows; i++) {
    int *row = grid[i];
    // find max row for this row to use.
    int max_row = -1;
    for (int j = 0; j < cols; j++) {
      int v = row[j];
      if (v > max_row)
        max_row = v;
    }
    for (int j = 0; j < cols; j++) {
      if (mxcolsLen == 0) {
        // find max column value.
        int max_col = -1;
        for (int i = 0; i < rows; i++) {
          int v = grid[i][j];
          if (v > max_col)
            max_col = v;
        }
        max_cols[j] = max_col;
      }
      int value = grid[i][j];
      // diff is the difference between min of maxes minus value.
      int diff = max_row < max_cols[j] ? max_row - value : max_cols[j] - value;
      if (diff > 0) {
        max_increase += diff;
      }
    }
  }
  free(max_cols);
  return max_increase;
}
