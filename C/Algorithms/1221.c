int balancedStringSplit(char *s) {
  int count = 0, track = 1;
  char cur_char = *s++;

  while (*s) {
    char next_char = *s++;
    if (cur_char != next_char) {
      track--;
      if (track == 0) {
        count++;
        if (*s)
          cur_char = *s++;
        else
          break;
        track = 1;
      }
    } else
      track += 1;
  }
  return count;
}