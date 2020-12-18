#include "uthash/src/uthash.h"
#include <stdlib.h>

// Add only if it doesn't exist.
#define ADD_IF_UNIQUE(set, value)                                              \
  s_entry *e;                                                                  \
  HASH_FIND_INT(set, &value, e);                                               \
  if (!e) {                                                                    \
    e = malloc(sizeof(*e));                                                    \
    e->key = value;                                                            \
    HASH_ADD_INT(set, key, e);                                                 \
  }

typedef struct {
  int key;
  UT_hash_handle hh;
} s_entry;

// Perform intersection.
int *intersect(s_entry **s1, s_entry **s2, int *retSize) {
  // Find which is smaller.
  s_entry **smaller, **larger;
  int s1size = HASH_COUNT(*s1), s2size = HASH_COUNT(*s2), size;
  if (s1size > s2size) {
    smaller = s2;
    larger = s1;
    size = s2size;
  } else {
    smaller = s1;
    larger = s2;
    size = s1size;
  }

  // Max size will be same as size of smallest set.
  int *result = malloc(s1size * sizeof(*result)), length = 0;
  // intersect.
  s_entry *cur, *tmp;
  HASH_ITER(hh, *smaller, cur, tmp) {
    s_entry *e;
    HASH_FIND_INT(*larger, &cur->key, e);
    if (e) {
      result[length++] = cur->key;
    }
  }
  // Clear sets now.
  HASH_CLEAR(hh, *s1);
  HASH_CLEAR(hh, *s2);

  *retSize = length;
  return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
                  int *returnSize) {
  // build the sets.
  s_entry *s1 = NULL, *s2 = NULL;
  for (int i = 0; i < nums1Size; i++) {
    int value = nums1[i];
    ADD_IF_UNIQUE(s1, value);
  }
  for (int i = 0; i < nums2Size; i++) {
    int value = nums2[i];
    ADD_IF_UNIQUE(s2, value);
  }
  // intersect clears sets.
  int *result = intersect(&s1, &s2, returnSize);
  return result;
}
