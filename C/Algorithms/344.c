void reverseString(char *s, int sSize) {
  if (sSize == 0)
    return;

  char *end = s + sSize - 1;
  do {
    if ((end != s) && (*end != *s)) {
      *end ^= *s;
      *s ^= *end;
      *end ^= *s;
    }
  } while (++s < --end);
}
