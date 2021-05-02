int secondHighest(char *s) {
  int max = 47, second_max = 47;
  while (*s != NULL) {
    int c = *s++;
    if (c > 47 && c < 58) {
      if (c > max) {
        if (max > second_max)
          second_max = max;
        max = c;
      } else if (c > second_max && c != max)
        second_max = c;
    }
  }
  return second_max == 47 ? -1 : second_max - 48;
}