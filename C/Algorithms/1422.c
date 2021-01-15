int maxScore(char *s) {
  int l = 1, length = 0;
  int max = *s == '1' ? -1 : 1;
  char *runner = s;
  while (*runner) {
    length++;
    // Count ones.
    if (*runner++ == '1')
      max++;
  }
  // We've counted the first char.
  s++;
  int tmp = max;
  // s+1, splits must be non-empty.
  while (*(s + 1)) {
    tmp += *s++ == '0' ? 1 : -1;
    if (tmp > max) {
      max = tmp;
    }
  }
  return max;
}
