int countSegments(char *s) {
  uint segments = *s && *s != ' ';
  while (*s) {
    if (*s++ == ' ') {
      while (*s == ' ')
        s++;
      if (!*s)
        break;
      segments++;
    }
  }
  return segments;
}