char findTheDifference(char *s, char *t) {
  int x = 0;
  while (*s)
    x ^= *s++ ^ *t++;
  return (char)(x ^ *t);
}
