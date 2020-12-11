#include "uthash/src/uthash.h"
#include <stdlib.h>

// Add to w_entry map. We know we have distinct elements.
#define ADD_TO_MAP(map, char, val)                                             \
  w_entry *entry = malloc(sizeof(*entry));                                     \
  entry->key = (int)char;                                                      \
  entry->value = val;                                                          \
  HASH_ADD_INT(map, key, entry);

// Get value from map. Returns NULL if char isn't in map
// (which shouldn't be possible.) Value is placed into into.
#define GET(map, char, into)                                                   \
  w_entry *entry;                                                              \
  int k = char;                                                                \
  HASH_FIND_INT(map, &k, entry);                                               \
  if (!entry) {                                                                \
    return NULL;                                                               \
  }                                                                            \
  *into = entry->value;

typedef struct {
  int key; // hold chars as ints.
  int value;
  UT_hash_handle hh;
} w_entry;

const char *lcEng = "abcdefghijklmnopqrstuvwxyz";

int *numberOfLines(int *widths, int widthsSize, char *s, int *returnSize) {
  int line = 0, lines = 0;
  w_entry *dwidths = NULL;
  // Add char -> value pairs to dwidths map.
  for (int i = 0; i < widthsSize; i++) {
    ADD_TO_MAP(dwidths, lcEng[i], widths[i]);
  }

  // Calculate lines needed.
  char c;
  int width;
  while ((c = *s++)) {
    GET(dwidths, c, &width);
    line += width;
    if (line > 100) {
      lines++;
      line = width;
    }
  }
  // Clear map:
  HASH_CLEAR(hh, dwidths);

  // Create result and return.
  int *res = malloc(2 * sizeof(*res));
  res[0] = lines + (line > 0 ? 1 : 0);
  res[1] = line;
  *returnSize = 2;
  return res;
}
