int peakIndexInMountainArray(int *arr, int arrSize) {
  int i = 0, j = arrSize;
  int m = (j + i) / 2;
  while (1) {
    int mid = arr[m];
    if (arr[m + 1] > mid)
      i = m + 1;
    else if (arr[m - 1] > mid)
      j = m - 1;
    else
      return m;
    m = (j + i) / 2;
  }
}
