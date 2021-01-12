#include "uthash/src/uthash.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int key;
  UT_hash_handle hh;
} filter_t;

bool containsDuplicate(int *nums, int numsSize) {
  filter_t *filter = NULL;
  for (int i = 0; i < numsSize; i++) {
    filter_t *p;
    int k = nums[i];
    HASH_FIND_INT(filter, &k, p);
    if (p) {
      return 1;
    } else {
      p = malloc(sizeof(*p));
      (*p).key = k;
      HASH_ADD_INT(filter, key, p);
    }
  }
  return 0;
}
