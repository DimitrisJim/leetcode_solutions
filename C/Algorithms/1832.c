bool checkIfPangram(char *sentence) {
  // Use array as small map.
  int arr[26] = {0}, count = 0;
  while (*sentence) {
    uint index = *sentence++ - 97;
    if (arr[index] == 0) {
      arr[index] = 1;
      count++;
      if (count == 26)
        return true;
    }
  }
  return false;
}