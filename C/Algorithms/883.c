#include <stddef.h>

int projectionArea(int **grid, int gridSize, int *gridColSize) {
  // views for each dimension
  int *view_y = NULL;
  int view_z = 0, view_x = 0, cols = gridColSize[0];

  for (int i = 0; i < gridSize; i++) {
    if (!view_y)
      view_y = grid[0];
    int max_value = 0, count = 0;
    for (int j = 0; j < cols; j++) {
      int value = grid[i][j];
      if (value > 0) {
        // for view_z
        count++;
        // for view_x
        if (value > max_value)
          max_value = value;
        // update view_y
        if (value > view_y[j])
          view_y[j] = value;
      }
    }
    // Update counters.
    view_z += count;
    view_x += max_value;
  }
  int y_sum = 0;
  for (int i = 0; i < cols; i++)
    y_sum += view_y[i];
  return view_z + view_x + y_sum;
}
