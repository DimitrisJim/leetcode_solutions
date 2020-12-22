int numberOfMatches(int n) {
  int c = 0, r;
  while (n > 1) {
    r = n % 2, n = n / 2;
    c += n + r;
  }
  return c;
}
