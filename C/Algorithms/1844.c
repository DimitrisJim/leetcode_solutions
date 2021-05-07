char *replaceDigits(char *s) {
  // Keep track of start.
  char *b = s;
  // while next two chars are not NULL.
  while (*s && *(s + 1)) {
    // get character and then set s to char + shift
    int chr = *s++;
    *s = chr + (*s - '0');
    s++;
  }
  return b;
}