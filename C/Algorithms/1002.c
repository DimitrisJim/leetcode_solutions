#include <stdlib.h>
#include <string.h>

typedef struct {
  int key;
  int count;
  UT_hash_handle hh;
} c_entry;

void count_values(c_entry **c, char *value) {
  int chr;
  while ((chr = *value++)) {
    c_entry *ne;
    HASH_FIND_INT(*c, &chr, ne);
    if (!ne) {
      // value not found.
      ne = malloc(sizeof(*ne));
      ne->key = chr;
      ne->count = 1;
      HASH_ADD_INT(*c, key, ne);
    } else {
      ne->count++;
    }
  }
}

void inplace_and(c_entry **common, c_entry **other) {
  c_entry *ce, *tmp;
  HASH_ITER(hh, *common, ce, tmp) {
    c_entry *ne;
    HASH_FIND_INT(*other, &ce->key, ne);
    if (ne) {
      // If we have a smaller count, update.
      if (ne->count < ce->count) {
        ce->count = ne->count;
      }
    } else {
      ce->count = 0;
    }
  }
  // remove all zeroes in common:
  HASH_ITER(hh, *common, ce, tmp) {
    if (ce->count == 0)
      HASH_DEL(*common, ce);
  }
}

// Go from counter to char ** array.
char **counter_to_array(c_entry **common, unsigned *res_size) {
  int size = HASH_COUNT(*common), length = 0;
  char **res = malloc(size * sizeof(*res));
  c_entry *ce, *tmp;
  // Go through common and build resulting array.
  HASH_ITER(hh, *common, ce, tmp) {
    char key = (char)ce->key;
    for (int i = 0; i < ce->count; i++) {
      // resize if necessary
      if (length == size) {
        size *= 2;
        res = realloc(res, size * sizeof(*res));
      }
      res[length] = malloc(2);
      strncpy(res[length++], (char[2]){key, '\0'}, 2);
    }
    // done with it.
    HASH_DEL(*common, ce);
  }
  *res_size = length;
  return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **A, int ASize, int *returnSize) {
  c_entry *common = NULL;
  count_values(&common, A[0]);
  for (int i = 1; i < ASize; i++) {
    c_entry *other = NULL;
    // Count values for other and find common chars.
    count_values(&other, A[i]);
    inplace_and(&common, &other);
    HASH_CLEAR(hh, other);
    // bail if at any point size of common is 0.
    if (HASH_COUNT(common) == 0) {
      HASH_CLEAR(hh, common);
      *returnSize = 0;
      return (char **)malloc(0);
    }
  }
  // Set size, build array and return.
  return counter_to_array(&common, returnSize);
}
