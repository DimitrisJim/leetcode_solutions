#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  int value;
  UT_hash_handle hh;
} table_t;

// Go through nums from left and right. Find leftmost and rightmost
// occurences for each item in items. Minimum length will be the minimum
// of the differences of end - start for each item.
int find_min(int *nums, int numsLen, int *items, int itemsLen, int deg) {
  int min_length = numsLen;
  for (int i = 0; i < itemsLen; i++) {
    int item = items[i], start = 0, end = numsLen - 1;
    while (start < end) {
      int s = nums[start], e = nums[end];
      if (s != item)
        start++;
      if (e != item)
        end--;
      if (e == item && s == item) {
        int diff = end - start + 1;
        if (diff == deg)
          return diff;
        if (diff < min_length)
          min_length = diff;
        break;
      }
    }
  }
  return min_length;
}

// Build a table of counts for each value in nums.
void make_counts(table_t **counter, int *nums, int numsLen) {
  // Go through numbers and build a count.
  for (int i = 0; i < numsLen; i++) {
    int value = nums[i];
    table_t *tmp;
    HASH_FIND_INT(*counter, &value, tmp);
    if (tmp) {
      tmp->value++;
    } else {
      tmp = malloc(sizeof(*tmp));
      tmp->key = value;
      tmp->value = 1;
      HASH_ADD_INT(*counter, key, tmp);
    }
  }
}

int findShortestSubArray(int *nums, int numsSize) {
  table_t *counter = NULL, *cur, *next;
  make_counts(&counter, nums, numsSize);

  // Go with an initial size of 4 for now.
  int size = 4, length = 0, degree = 0;
  int *items = malloc(size * sizeof(*items));
  // Iterate through counter and only keep items
  // with max degree.
  HASH_ITER(hh, counter, cur, next) {
    int value = cur->value, key = cur->key;
    if (value > degree) {
      degree = value;
      // Reset items length.
      length = 0;
      items[length++] = key;
    } else if (value == degree) {
      if (length + 1 == size) {
        size *= 1.5;
        items = realloc(items, size * sizeof(*items));
      }
      items[length++] = key;
    }
    HASH_DEL(counter, cur);
  }
  HASH_CLEAR(hh, counter);

  // degree == 1 means nums has unique numbers.
  if (degree == 1) {
    free(items);
    return 1;
  }
  // Find min, clean-up, return.
  int result = find_min(nums, numsSize, items, length, degree);
  free(items);
  return result;
}
