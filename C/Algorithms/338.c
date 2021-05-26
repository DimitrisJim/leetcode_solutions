/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
  int *res = calloc(++n, sizeof(*res));
  for (int i = 1; i < n; i++) {
    // i >> 1 will always be smaller than `i` and
    // present in the array.
    // i & 1 checks if we shifted off a zero or a one
    // (and, respectively adds 0 or 1 to the result)
    res[i] = res[i >> 1] + (i & 1);
  }
  *returnSize = n;
  return res;
}