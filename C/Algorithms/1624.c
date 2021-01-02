#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  int min;
  int max;
  UT_hash_handle hh;
} d_entry;

int maxLengthBetweenEqualCharacters(char *s) {
  // Build distances.
  d_entry *d = NULL;
  int i = 0;
  while (*s) {
    int chr = *s++;
    d_entry *t;
    HASH_FIND_INT(d, &chr, t);
    if (!t) {
      t = malloc(sizeof(*t));
      t->key = chr;
      t->min = i;
      t->max = i;
      HASH_ADD_INT(d, key, t);
    } else {
      if (i > t->max) {
        t->max = i;
      }
    }
    i++;
  }

  // Find max distance:
  d_entry *cur, *tmp;
  int max_dst = -1;
  HASH_ITER(hh, d, cur, tmp) {
    if (cur->min != cur->max) {
      int diff = cur->max - cur->min - 1;
      if (diff > max_dst)
        max_dst = diff;
    }
    HASH_DEL(d, cur);
  }
  return max_dst;
}
