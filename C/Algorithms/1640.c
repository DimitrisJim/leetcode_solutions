/* uthash is header only library provided for us.
 * Desafortunadamente, I'll need to endure errors its
 * absence here produces.
 **/
#include "uthash.h"
#include <stdbool.h>
#include <stdlib.h>

struct hash_entry {
  int id;            /* Only care about keys */
  UT_hash_handle hh; /* Makes this structure hashable */
};

int has_value(struct hash_entry *h, int val) {
  struct hash_entry *s;
  HASH_FIND_INT(h, &val, s); /* id already in the hash? */
  if (s == NULL) {
    return 0;
  }
  return 1;
}

bool canFormArray(int *arr, int arrSize, int **pieces, int piecesSize,
                  int *piecesColSize) {
  // Initialize, must be NULL.
  struct hash_entry *elems = NULL;
  // Create hash table holding arr values as keys.
  for (int i = 0; i < arrSize; i++) {
    struct hash_entry *s = malloc(sizeof(*s));
    s->id = arr[i];
    HASH_ADD_INT(elems, id, s);
  }
  for (int i = 0; i < piecesSize; i++) {
    // If size of pieces[i] == 1, we stop here.
    if (!has_value(elems, pieces[i][0]))
      return false;
    // else, we must check if the subsequence matches.
    if (piecesColSize[i] > 1) {
      // Find index.
      int idx = 0;
      for (; idx < arrSize; idx++) {
        if (arr[idx] == pieces[i][0]) {
          break;
        }
      }
      // Check if we match.
      for (int j = 1; j < piecesColSize[i]; j++) {
        int idx_ = idx + j;
        if ((idx_ >= arrSize) || (arr[idx_] != pieces[i][j])) {
          return false;
        }
      }
    }
  }
  return true;
}
