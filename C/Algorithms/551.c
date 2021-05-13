bool checkRecord(char *s) {
  int consecutive = 0, a_count = 0;
  do {
    if (*s == 'L') {
      consecutive++;
      if (consecutive == 3)
        return false;
      continue;
    } else if (*s == 'A') {
      a_count++;
      if (a_count == 2)
        return false;
    }
    consecutive = 0;
  } while (*s++);
  return true;
}