#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  int pos;
  UT_hash_handle hh;
} table_t;

int *twoSum(int *nums, int numsSize, int k, int *returnSize) {
  table_t *seen = NULL;
  int idx1 = 0, idx2 = 0;
  for (int i = 0; i < numsSize; i++) {
    table_t *tmp;
    // Search for diff in mapping.
    int diff = k - nums[i];
    HASH_FIND_INT(seen, &diff, tmp);
    // If found, grab associated position.
    if (tmp) {
      idx1 = i;
      idx2 = tmp->pos;
      break;
      // Else, add value to mapping.
    } else {
      tmp = malloc(sizeof(*tmp));
      tmp->key = nums[i];
      tmp->pos = i;
      HASH_ADD_INT(seen, key, tmp);
    }
  }
  // Clean-up, return.
  *returnSize = 2;
  int *ret = malloc(2 * sizeof(*ret));
  ret[0] = idx1;
  ret[1] = idx2;
  HASH_CLEAR(hh, seen);
  return ret;
}
