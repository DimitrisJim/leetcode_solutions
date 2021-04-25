int sumBase(int n, int k) {
  uint s = 0;
  while (n >= k) {
    int r = n % k;
    n /= k;
    s += r;
  }
  return s + n;
}