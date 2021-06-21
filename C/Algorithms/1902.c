char *largestOddNumber(char *num) {
  int set[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, len = strlen(num);
  for (int i = len - 1; i >= 0; i--) {
    if (set[num[i] - 48])
      break;
    num[i] = '\0';
  }
  return num;
}