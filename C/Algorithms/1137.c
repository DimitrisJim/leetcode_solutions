int tribonacci(int n) {
  int a = 0, b = 1, c = 1;
  for (int i = 0; i < n - 2; i++) {
    int tmp_a = a, tmp_b = b;
    a = b;
    b = c;
    c = tmp_a + tmp_b + c;
  }

  // take care of n == 0 case.
  return n ? c : 0;
}
