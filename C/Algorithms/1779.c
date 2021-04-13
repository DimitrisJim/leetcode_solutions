int nearestValidPoint(int x, int y, int **points, int pointsSize,
                      int *pointsColSize) {
  int previous_min = 10 << 10, index = -1, dst = 10 << 10;
  for (int i = 0; i < pointsSize; i++) {
    int xi = *points[i], yi = *(points[i] + 1);
    if (xi == x)
      dst = yi - y;
    else if (yi == y)
      dst = xi - x;
    else
      continue;
    dst = dst < 0 ? -dst : dst;
    if (dst < previous_min) {
      previous_min = dst;
      index = i;
    }
  }
  return index;
}