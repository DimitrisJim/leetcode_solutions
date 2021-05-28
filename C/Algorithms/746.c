int minCostClimbingStairs(int *cost, int costSize) {
  int tableSize = costSize + 2;
  int *table = malloc(tableSize * sizeof(*table));
  table[0] = 0;
  for (int i = 1; i < tableSize; i++)
    table[i] = 2 << 20;
  for (int i = 1; i < tableSize; i++) {
    int previous = table[i - 1];
    int cand_1 = previous + (i < costSize ? cost[i - 1] : 0);
    if (cand_1 < table[i])
      table[i] = cand_1;

    int j = i + 1;
    if (j < tableSize) {
      cand_1 = previous + (i < costSize ? cost[i] : 0);
      if (cand_1 < table[j])
        table[j] = cand_1;
    }
  }
  int res = table[tableSize - 1];
  free(table);
  return res;
}