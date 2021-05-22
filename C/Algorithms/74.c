bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize,
                  int target) {
  int m = matrixColSize[0], n = matrixSize;
  for (int i = 0; i < n; i++) {
    int *a = matrix[i];
    // Don't search in rows where final element is < target.
    if (target > a[m - 1])
      continue;

    int lo = 0, hi = m;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (a[mid] < target)
        lo = mid + 1;
      else {
        if (a[mid] == target)
          return true;
        hi = mid;
      }
    }
  }
  return false;
}