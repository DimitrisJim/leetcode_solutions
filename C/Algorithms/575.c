#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  UT_hash_handle hh;
} s_entry;

int distributeCandies(int *candyType, int candyTypeSize) {
  int ammount = candyTypeSize / 2, dc = 0;
  // Fill set up.
  s_entry *set = NULL;
  for (int i = 0; i < candyTypeSize; i++) {
    int value = candyType[i];
    s_entry *t;
    HASH_FIND_INT(set, &value, t);
    if (!t) {
      t = malloc(sizeof(*t));
      t->key = value;
      HASH_ADD_INT(set, key, t);
      dc++;
    }
  }
  HASH_CLEAR(hh, set);
  // return.
  return dc < ammount ? dc : ammount;
}
