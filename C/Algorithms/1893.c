// I really need to clear-up sorting of
// multidim arrays, it's a mess.
int cmpv(const void *x, const void *y) {
  const int *a = *(const int **)x;
  const int *b = *(const int **)y;

  return (a[1] > b[1]) - (a[1] < b[1]);
}

bool isCovered(int **ranges, int rangesSize, int *rangesColSize, int left,
               int right) {
  qsort(ranges, rangesSize, sizeof ranges[0], cmpv);
  int i = 0;
  while (left <= right && i < rangesSize) {
    int l = ranges[i][0], r = ranges[i][1];
    if (l <= left && left <= r)
      left = r + 1;
    if (l <= right && right <= r)
      right = l - 1;
    i++;
  }
  return left > right;
}