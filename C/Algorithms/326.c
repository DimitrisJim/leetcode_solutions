bool isPowerOfThree(int n) {
  if (!(n & 1) || (n <= 0)) {
    return false;
  }
  float rs = log(n) / log(3);
  float diff = round(rs) - rs;
  return (diff < 0 ? -diff : diff) < 1e-10;
}