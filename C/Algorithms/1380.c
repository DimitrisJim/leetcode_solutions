#include "uthash/src/uthash.h"
#include <stdbool.h>
#include <stdlib.h>

// Max as stated by problem statement.
#define MAX_VAL 100001

// Use as set to hold mins.
typedef struct {
  int value;
  UT_hash_handle hh;
} s_entry;

// Simple membership testing.
inline bool has_value(s_entry *mins, int value) {
  s_entry *s;

  HASH_FIND_INT(mins, &value, s);
  return s ? true : false;
}

// Free elements.
void free_set(s_entry *set) {
  s_entry *current_entry, *tmp;

  // iterate through and delete entries.
  HASH_ITER(hh, set, current_entry, tmp) { HASH_DEL(set, current_entry); }
}

int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize,
                  int *returnSize) {
  // Hold it around, its the same for every column.
  int colSize = *matrixColSize;
  // Hold max values in array and min values in set.
  // Zero-out maxes.
  int *maxes = calloc(colSize, sizeof(*maxes));
  s_entry *mins = NULL;

  for (int i = 0; i < matrixSize; i++) {
    int min = matrix[i][0];
    for (int j = 0; j < colSize; j++) {
      int element = matrix[i][j];
      if (element < min) {
        min = element;
      }
      if (*(maxes + j) < element) {
        *(maxes + j) = element;
      }
    }
    // Add minimum to set:
    s_entry *s = malloc(sizeof(*s));
    s->value = min;
    HASH_ADD_INT(mins, value, s); /* value: name of key */
  }

  // Build result and return:
  // Rather arbitrary but make size 1/2of rowSize
  int resSize = (colSize / 2) + 1; // +1 guards against colSize == 1.
  int *res = malloc(sizeof(*res) * resSize), length = 0;
  for (int i = 0; i < colSize; i++) {
    // if set has maxes[i] add to res:
    if (has_value(mins, maxes[i])) {
      if (length == resSize) {
        resSize *= 2;
        // make it matrixSize and be done.
        res = realloc(res, resSize * sizeof(*res));
      }
      res[length++] = maxes[i];
    }
  }
  // free the mins set.
  free(maxes);
  *returnSize = length;
  return res;
}
