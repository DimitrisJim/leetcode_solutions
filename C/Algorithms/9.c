bool isPalindrome(int x) {
  if (x < 0)
    return false;

  // To string, first.
  uint length = snprintf(NULL, 0, "%d", x);
  char *buf = malloc(length + 1);
  snprintf(buf, length + 1, "%d", x);

  // Go through and check characters.
  uint i = 0, j = length - 1;
  while (i < j) {
    if (buf[i++] != buf[j--])
      return false;
  }
  return true;
}