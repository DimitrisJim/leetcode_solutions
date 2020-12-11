#include "uthash/src/uthash.h"
#include <stdlib.h>

// Add a value to the map (increment by one) if already present.
#define ADD_TO_MAP(map, ds)                                                    \
  d_entry *d;                                                                  \
  HASH_FIND_INT(map, &ds, d);                                                  \
  if (!d) {                                                                    \
    d = malloc(sizeof(*d));                                                    \
    d->dsum = ds;                                                              \
    d->value = 1;                                                              \
    HASH_ADD_INT(map, ds, d);                                                  \
  } else {                                                                     \
    d->value++;                                                                \
  }

// Our uthash struct.
typedef struct {
  int dsum;
  int value;
  UT_hash_handle hh;
} d_entry;

// Sort ascending. (i.e go from back when
// looking for largest values.)
int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return ((a > b) - (a < b));
}

// Only return values. Clears map.
int *map_to_vec(d_entry *map, int *returnSize) {
  *returnSize = HASH_COUNT(map);
  int *res = malloc(*returnSize * sizeof(*res)), i = 0;

  d_entry *cur, *tmp;
  HASH_ITER(hh, map, cur, tmp) { res[i++] = cur->value; }
  HASH_CLEAR(hh, map);
  return res;
}

int countLargestGroup(int n) {
  d_entry *map = NULL;
  // Build the map for i digit count -> occcurences.
  for (int i = 1; i < n + 1; i++) {
    // Count digits.
    int k = i, dsum = k % 10;
    while (k /= 10)
      dsum += k % 10;
    ADD_TO_MAP(map, dsum);
  }

  // Get values, sort, find count.
  int retSize, count = 0, group = 0;
  int *values = map_to_vec(map, &retSize);
  qsort(values, retSize, sizeof(*values), cmpi);
  for (int i = retSize - 1; i >= 0; i--) {
    if (group == 0) {
      group = values[i];
      count++;
    } else {
      if (group != values[i])
        return count;
      count++;
    }
  }
  free(values);
  return count;
}
