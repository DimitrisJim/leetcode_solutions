int findKthPositive(int *arr, int arrSize, int k) {
  int start = 1;
  for (int i = 0; i < arrSize; i++) {
    int j = *(arr + i);
    if (start == j)
      start++;
    else {
      int step = j - start;
      if (step >= k)
        return start + k - 1;
      k -= step;
      start = j + 1;
    }
  }
  return start + k - 1;
}
