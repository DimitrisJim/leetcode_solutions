char *truncateSentence(char *s, int k) {
  char *runner = s;
  int i = 0;
  // Re-use s by ending it when we reach the final space.
  while (*runner) {
    if (*runner++ == ' ')
      k--;
    if (k == 0) {
      s[i] = '\0';
      break;
    }
    i++;
  }
  return s;
}