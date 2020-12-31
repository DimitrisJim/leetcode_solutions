int findSpecialInteger(int *arr, int arrSize) {
  int threshold = (arrSize * 0.25), count = 1;
  for (int i = 1; i < arrSize; i++) {
    if (*(arr + i - 1) == *(arr + i)) {
      count++;
      if (count > threshold)
        return *(arr + i);
    } else
      count = 1;
  }
  return arr[0];
}
