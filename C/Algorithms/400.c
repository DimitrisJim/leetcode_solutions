// digits until 10 * i for i in {1..9}
static long limits[9] = {9,       189,      2889,      38889,     488889,
                         5888889, 68888889, 788888889, 8888888889};

int findNthDigit(int n) {
  if (n < 10)
    return n;

  int i = 0;
  while (n > limits[i])
    i++;

  // need the largest value smaller than n.
  long base = limits[i - 1];
  // i == 0 => 1 digits. i == 1 => 2 digits..
  long pos = (n - (base + 1)) / (i + 1), digit = i - (n - (base + 1)) % (i + 1);
  // get digit at position digit with typical while loop.
  long k = pow(10, i) + pos;
  int d = 0;
  while (k) {
    d = k % 10;
    if (digit == 0)
      break;
    digit--;
    k /= 10;
  }
  return d;
}