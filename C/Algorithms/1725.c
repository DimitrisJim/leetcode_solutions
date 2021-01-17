int countGoodRectangles(int **rectangles, int rectanglesSize,
                        int *rectanglesColSize) {
  int max = 0, count = 0;
  for (int i = 0; i < rectanglesSize; i++) {
    int a = rectangles[i][0], b = rectangles[i][1];
    int m = a > b ? b : a;
    if (m == max)
      count++;
    else if (m > max) {
      count = 1;
      max = m;
    }
  }
  return count;
}
