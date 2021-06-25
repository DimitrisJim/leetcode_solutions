double myPow(double x, int n) {
  if (x == 0 || x == 1)
    return x;
  // flip sign of exponent.
  bool pos_exp = true;
  long nl = n;
  if (n < 0) {
    pos_exp = false;
    nl = -nl;
  }

  double result = 1;
  while (nl) {
    if (nl & 1)
      result *= x;
    x *= x;
    nl /= 2;
  }
  // a ** (-b) => 1 / a ** b
  return pos_exp ? result : 1 / result;
}