#include <stdlib.h>

// Perform action based on operation.
#define HANDLE_OP(OP, ARR, LEN)                                                \
  if (OP[0] == 'C') {                                                          \
    LEN--;                                                                     \
  } else if (OP[0] == '+') {                                                   \
    ARR[LEN++] = ARR[LEN - 1] + ARR[LEN - 2];                                  \
  } else if (OP[0] == 'D') {                                                   \
    ARR[LEN++] = ARR[LEN - 1] * 2;                                             \
  } else {                                                                     \
    ARR[LEN++] = atoi(OP);                                                     \
  }

// Reallocate, if needed.
#define MAYBE_REALLOC(ARR, LENGTH, SIZE)                                       \
  if (LENGTH + 1 >= SIZE) {                                                    \
    SIZE *= 1.25;                                                              \
    ARR = realloc(ARR, SIZE * sizeof(*ARR));                                   \
  }

int calPoints(char **ops, int opsSize) {
  int *score = malloc(opsSize * sizeof(*score)), size = opsSize, length = 0,
      i = 1;
  score[length++] = atoi(ops[0]);
  while (i < opsSize - 1) {
    char *op1 = ops[i];
    if ((ops[i + 1][0] == 'C') && (op1[0] != 'C')) {
      i += 2;
      continue;
    }
    MAYBE_REALLOC(score, length, size);
    HANDLE_OP(op1, score, length);
    i++;
  }
  if (i < opsSize) {
    MAYBE_REALLOC(score, length, size);
    HANDLE_OP(ops[opsSize - 1], score, length);
  }
  int sum = 0;
  for (int i = 0; i < length; i++)
    sum += score[i];
  return sum;
}
