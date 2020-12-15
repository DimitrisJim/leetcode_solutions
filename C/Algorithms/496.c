#include "uthash/src/uthash.h"
#include <stdlib.h>

// We have unique values, no need to find first.
#define ADD_TO_MAP(mapobj, val, idx)                                           \
  map *entry = malloc(sizeof(*entry));                                         \
  entry->value = val;                                                          \
  entry->index = idx;                                                          \
  HASH_ADD_INT(mapobj, value, entry);

// Can double as map has. Result is pointer to
// int that will hold result. -1 if not present.
#define MAP_GET(mapobj, val, result)                                           \
  map *entry;                                                                  \
  HASH_FIND_INT(mapobj, &val, entry);                                          \
  *result = entry ? entry->index : -1;

// We have unique values, no need to find first.
#define ADD_TO_SET(setobj, val)                                                \
  set *entry = malloc(sizeof(*entry));                                         \
  entry->key = val;                                                            \
  HASH_ADD_INT(setobj, key, entry);

// Structures for sets and maps.
typedef struct {
  int key;
  UT_hash_handle hh;
} set;

typedef struct {
  int value;
  int index;
  UT_hash_handle hh;
} map;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize) {
  int *result = malloc(nums1Size * sizeof(*result));
  set *seen = NULL;
  map *indices = NULL;

  // Initialize indices with value -> indices.
  // Initialize result to -1's.
  for (int i = 0; i < nums1Size; i++) {
    ADD_TO_MAP(indices, nums1[i], i);
    result[i] = -1;
  };

  // Iterate through nums2 first.
  for (int i = 0; i < nums2Size; i++) {
    int value = nums2[i];
    set *current, *temp;
    // Go through values in seen (if any).
    HASH_ITER(hh, seen, current, temp) {
      if (value > current->key) {
        // if its in seen, its in indices.
        // index will always be != -1.
        int index;
        MAP_GET(indices, current->key, &index);
        result[index] = value;
        // Remove from seen set.
        HASH_DEL(seen, current);
      }
    }
    int present;
    MAP_GET(indices, value, &present);
    if (present != -1) {
      ADD_TO_SET(seen, value);
    }
  }

  // Clean up and return.
  HASH_CLEAR(hh, indices);
  HASH_CLEAR(hh, seen);
  *returnSize = nums1Size;
  return result;
}
