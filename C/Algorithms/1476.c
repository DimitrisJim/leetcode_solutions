#include <stdlib.h>

typedef struct {
  int **rectangle;
} SubrectangleQueries;

SubrectangleQueries *subrectangleQueriesCreate(int **rectangle,
                                               int rectangleSize,
                                               int *rectangleColSize) {
  SubrectangleQueries *sq = malloc(sizeof(*sq));
  // Since queries are guaranteed to be in range, don't
  // really need to keep rows, cols around.
  sq->rectangle = rectangle;
  return sq;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries *sq, int row1,
                                           int col1, int row2, int col2,
                                           int newValue) {
  for (int i = row1; i <= row2; i++)
    for (int j = col1; j <= col2; j++)
      sq->rectangle[i][j] = newValue;
}

int subrectangleQueriesGetValue(SubrectangleQueries *sq, int row, int col) {
  return sq->rectangle[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries *sq) { free(sq); }
