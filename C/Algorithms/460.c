int count_changes(char *s, char expected) {
  int changes = 0;
  while (*s) {
    if (*s++ == expected)
      changes++;
    expected = expected == '0' ? '1' : '0';
  }
  return changes;
}

int minOperations(char *s) {
  char *ts = s;
  int min_zero = count_changes(ts, '0'), min_one = count_changes(s, '1');
  return min_zero < min_one ? min_zero : min_one;
}