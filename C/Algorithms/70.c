int climbStairs(int n) {
  if (n == 1)
    return 1;
  long a = 1, b = 2;
  n--;
  while (--n > 0) {
    long temp = b;
    b = a + b;
    a = temp;
  }
  return b;
}