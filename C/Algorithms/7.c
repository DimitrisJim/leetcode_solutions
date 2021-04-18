int reverse(int x) {
  int bound = x < 0 ? -0x80000000 : 0x7FFFFFFF;
  // Handle edge case where x is equal to largest negative which
  // cannot be represented as positive.
  if (x < 0 && x == bound)
    return 0;
  x = x < 0 ? -x : x;

  // Build digits array for x.
  int digits[10] = {0}, ix = 0, r;
  while (x) {
    r = x % 10;
    x = x / 10;
    digits[ix++] = r;
  }

  if (ix == 10) {
    // If x has 10 digits, need to check we won't overflow. Build
    // digits array for bound
    int digits_n[10] = {0}, in = 0, n = bound < 0 ? -(bound + 1) : bound;
    while (n) {
      r = n % 10;
      n = n / 10;
      digits_n[in++] = r;
    }
    // Adjust for +1 added before.
    if (bound < 0)
      digits_n[0] += 1;
    // And check that digits in x are smaller.
    for (int i = 0; i < 10; i++) {
      int a = digits[i], b = digits_n[9 - i];
      if (a > b)
        return 0;
      if (a < b)
        break;
    }
  }
  // Build result and return it.
  int res = 0;
  for (int i = ix - 1, j = 0; i >= 0; i--, j++) {
    res += digits[i] * pow(10, j);
  }
  return bound < 0 ? -res : res;
}