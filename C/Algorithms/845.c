int longestMountain(int *arr, int arrSize) {
  int i = 0, max = 0, end = arrSize - 1;
  while (i < end) {
    int up = 1, k = i;
    while (k < end && arr[k] < arr[k + 1]) {
      up++;
      k++;
    }
    // Start looking for a way down if we've found a
    // way up.
    if (up > 1) {
      int down = 0;
      while (k < end && arr[k] > arr[k + 1]) {
        down++;
        k++;
      }
      // must have both down and up to have a mountain.
      if (down) {
        int tmp = up + down;
        max = max > tmp ? max : tmp;
        i += down - 1;
      }
    }
    // start looking again after the peak (if none were found
    // this will be == 1)
    i += up;
  }
  return max;
}