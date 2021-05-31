int lengthOfLastWord(char *s) {
  int count;
  while (*s) {
    // reset count if we continue
    count = 0;
    while (*s && *s != ' ') {
      s++;
      count++;
    }
    while (*s && *s == ' ')
      s++;
  }
  return count;
}