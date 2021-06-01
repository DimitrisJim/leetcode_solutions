int countGoodSubstrings(char *s) {
  // yes, could do it w/o strlen but meh.
  int count = 0, i = 2, end = strlen(s);
  while (i < end) {
    char a = s[i - 2], b = s[i - 1], c = s[i];
    if (a == b && b == c) {
      i += 2;
      continue;
    }
    count += a != b && b != c && a != c ? 1 : 0;
    i++;
  }
  return count;
}