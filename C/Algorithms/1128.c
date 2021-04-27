#define INDEX(i, j) (9 * (i - 1) - i + j)
#define COUNT_SIZE 73

int numEquivDominoPairs(int **dominoes, int dominoesSize,
                        int *dominoesColSize) {
  uint counter[COUNT_SIZE] = {0};
  // Count dominoes.
  for (int i = 0; i < dominoesSize; i++) {
    int a = dominoes[i][0], b = dominoes[i][1];
    if (a > b) {
      counter[INDEX(b, a)]++;
    } else {
      counter[INDEX(a, b)]++;
    }
  }

  // sum pairs
  uint sum = 0;
  for (int i = 0; i < COUNT_SIZE; i++) {
    int x = counter[i];
    if (x)
      sum += (x * (x - 1));
  }
  return sum / 2;
}