#include "uthash/src/uthash.h"

// We might have duplicates, find and then add if absent.
#define ADD_TO_SET(set, value)                                                 \
  s_entry *e;                                                                  \
  HASH_FIND_INT(set, &value, e);                                               \
  if (!e) {                                                                    \
    e = malloc(sizeof(*e));                                                    \
    e->col = value;                                                            \
    HASH_ADD_INT(set, col, e);                                                 \
  }

// Struct for our set.
typedef struct {
  int col;
  UT_hash_handle hh;
} s_entry;

int numSpecial(int **mat, int matSize, int *matColSize) {
  s_entry *occupied_columns = NULL;
  int rows = matSize, columns = matColSize[0], special = 0;

  for (int r = 0; r < rows; r++) {
    int bail = 0;
    for (int c = 0; c < columns; c++) {
      if (mat[r][c]) {
        // See if we've found a col with '1' previously.
        s_entry *t;
        HASH_FIND_INT(occupied_columns, &c, t);
        if (t)
          break;

        // check the rest of the row:
        int *row = mat[r];
        for (int k = c + 1; k < columns; k++) {
          if (row[k]) {
            // Add to occupied columns:
            ADD_TO_SET(occupied_columns, k);
            bail ^= 1; // toggle
            break;
          }
        }
        if (bail) {
          ADD_TO_SET(occupied_columns, c);
          break;
        }

        // Check rows, all of them.
        for (int k = 0; k < rows; k++) {
          // Don't be tricked by our own row.
          if (mat[k][c] && k != r) {
            ADD_TO_SET(occupied_columns, c);
            bail ^= 1;
            break;
          }
        }
        if (bail)
          break;

        // if we've reached this point, we're scot-free.
        ADD_TO_SET(occupied_columns, c);
        special++;
      }
    }
  }
  HASH_CLEAR(hh, occupied_columns);
  return special;
}
