bool isPowerOfTwo(int n) {
  if (n <= 0) {
    return false;
  }
  double res = log2(n);
  return ceil(res) == res;
}