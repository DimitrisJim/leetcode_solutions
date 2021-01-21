int firstUniqChar(char *s) {
  // Initialize to zeros (we only have lowercase
  // english chars).
  int chars[26] = {0}, i = 0;
  char *runner = s;
  // Count characters.
  while (*runner)
    chars[*runner++ - 97]++;
  while (*s) {
    // Find one with value == 1.
    if (chars[*s++ - 97] == 1)
      return i;
    i++;
  }
  return -1;
}
