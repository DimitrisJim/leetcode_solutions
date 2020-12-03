int fib(int N) {
  if (N == 0)
    return 0;
  if (N == 1 || N == 2)
    return 1;
  int f = 1, fprev = 1;
  N = N - 2;
  while (N--) {
    int temp = f;
    f = temp + fprev;
    fprev = temp;
  }
  return f;
}
