int find(char *t, char c, int start) {
  t = t + start;
  int pos = start;
  while (*t) {
    if (*t++ == c)
      return pos;
    pos++;
  }
  return -1;
}

bool isSubsequence(char *s, char *t) {
  int index = 0;
  while (*s) {
    char c = *s++;
    index = find(t, c, index);
    if (index == -1)
      return false;
    index++;
  }
  return true;
}