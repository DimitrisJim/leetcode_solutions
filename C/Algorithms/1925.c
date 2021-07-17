int countTriples(int n) {
  // precompute all powers from
  int count = 0, *pows = calloc(n, sizeof(*pows));
  for (int i = 3; i < n; i++)
    pows[i] = pow(i, 2);

  for (int i = 3; i < n - 1; i++) {
    int si = pows[i];
    for (int j = i + 1; j < n; j++) {
      // c must be integer (perfect square)
      double m = sqrt(si + pows[j]);
      // j only increases, cannot find m > n.
      if (m > n) {
        // means m was > n during first iteration,
        // i.e for consequent iterations it will
        // always be > n.
        if (j == i + 1) {
          return count * 2;
        }
        break;
      }
      // m <= n (wasn't aware of this mod trick.)
      if (floor(m) == m)
        count++;
    }
  }
  free(pows);
  return count * 2;
}