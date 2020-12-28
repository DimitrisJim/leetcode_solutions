#include <stdlib.h>
#include <string.h>

int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k,
                int *returnSize, int **returnColumnSizes) {
  // assume non-empty grid.
  int rows = gridSize, cols = gridColSize[0];

  // these are all the same regardless of case.
  *returnColumnSizes = malloc(rows * sizeof(**returnColumnSizes));
  for (int i = 0; i < rows; i++) {
    (*returnColumnSizes)[i] = cols;
  }
  *returnSize = gridSize;
  int d = k / cols, r = k % cols;
  // if d is > than number of rows, mod it.
  if (d >= rows) {
    d %= rows;
  }
  if (d == 0 && r == 0) {
    return grid;
  }

  // Resulting array.
  int **result = malloc(rows * sizeof(*result));
  // I should really freshen up memcpy stuff.
  if (r == 0) {
    int j = 0;
    for (int i = rows - d; i < rows; i++) {
      result[j] = malloc(cols * sizeof(**result));
      memcpy(result[j++], grid[i], cols * sizeof(int));
    }
    for (int i = 0; i < rows - d; i++) {
      result[j] = malloc(cols * sizeof(**result));
      memcpy(result[j++], grid[i], cols * sizeof(int));
    }
    return result;
  }

  // not muy proud of this.
  int length = rows * cols, fl = 0;
  int *flatgrid = malloc(length * sizeof(*flatgrid));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      flatgrid[fl++] = grid[i][j];
    }
  }

  int start = length - (d * cols + r), count = 0, i = 0;
  for (int k = start; k < length; k++) {
    if (count == cols) {
      grid[++i][0] = flatgrid[k];
      count = 1;
    } else {
      grid[i][count++] = flatgrid[k];
    }
  }
  for (int k = 0; k < start; k++) {
    if (count == cols) {
      grid[++i][0] = flatgrid[k];
      count = 1;
    } else {
      grid[i][count++] = flatgrid[k];
    }
  }
  free(flatgrid);
  return grid;
}
