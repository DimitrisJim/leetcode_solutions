// Returns area of triangle denoted by points
// p1, p2 and p3 using the Shoelace formula.
inline double shoelace(int *p1, int *p2, int *p3) {
  int x1 = p1[0], x2 = p2[0], x3 = p3[0], y1 = p1[1], y2 = p2[1], y3 = p3[1];

  double lace =
      0.5 * (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
  return lace > 0 ? lace : -lace;
}

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize) {
  double max = -1;

  // Go through triplets:
  int imax = pointsSize - 3 + 1, jmax = pointsSize - 3 + 2, kmax = pointsSize;
  for (int i = 0; i < imax; i++) {
    for (int j = i + 1; j < jmax; j++) {
      for (int k = j + 1; k < kmax; k++) {
        double area = shoelace(points[i], points[j], points[k]);
        if (area > max)
          max = area;
      }
    }
  }
  return max;
}
