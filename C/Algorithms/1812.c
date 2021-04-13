bool squareIsWhite(char *coordinates) {
  int col = (int)coordinates[0] - 96;
  int row = (int)coordinates[1];
  return (col & 1) != (row & 1)
}