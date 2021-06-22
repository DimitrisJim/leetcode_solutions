int findJudge(int n, int **trust, int trustSize, int *trustColSize) {
  int *trust_list = calloc(n, sizeof(int));
  for (int i = 0; i < trustSize; i++) {
    int p1 = trust[i][0] - 1, p2 = trust[i][1] - 1;
    trust_list[p1] = -1;
    if (trust_list[p2] >= 0)
      trust_list[p2]++;
  }
  for (int i = 0; i < n; i++) {
    if (trust_list[i] == n - 1) {
      free(trust_list);
      return i + 1;
    }
  }
  free(trust_list);
  return -1;
}