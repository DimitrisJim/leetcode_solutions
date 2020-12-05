int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size,
                         int d) {
  int count = 0, el, el2, top, bottom;
  for (int i = 0; i < arr1Size; i++) {
    el = *(arr1 + i);
    top = el + d, bottom = el - d;
    for (int j = 0; j < arr2Size; j++) {
      el2 = *(arr2 + j);
      if ((top >= el2) && (el2 >= bottom)) {
        count--;
        break;
      }
    }
    count++;
  }
  return count;
}
