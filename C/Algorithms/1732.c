int largestAltitude(int *gain, int gainSize) {
  int max_height = 0, height_i = 0;
  for (int i = 0; i < gainSize; i++) {
    height_i += gain[i];
    if (height_i > max_height)
      max_height = height_i;
  }
  return max_height;
}
