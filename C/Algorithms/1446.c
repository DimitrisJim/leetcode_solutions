int maxPower(char *s) {
  // Start from one since we advance s.
  int max_substring = 1, count = 1;
  char current = *s++;
  while (*s) {
    char n = *s++;
    if (current == n) {
      count++;
      if (count > max_substring)
        max_substring = count;
    } else {
      count = 1;
      current = n;
    }
  }
  return max_substring;
}
