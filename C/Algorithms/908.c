int smallestRangeI(int *A, int ASize, int K) {
  int min, max;
  min = max = A[0];
  // Find max and min of A.
  for (int i = 1; i < ASize; i++) {
    int value = *(A + i);
    if (value < min) {
      min = value;
    }
    if (value > max) {
      max = value;
    }
  }

  // Find difference.
  int diff = max - K - min;
  if (-K < diff && diff < K) {
    return 0;
  }
  return diff > 0 ? diff - K : diff + K;
}
