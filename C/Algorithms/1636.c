#include "uthash/src/uthash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value; // serves as key
  int freq;
  UT_hash_handle hh;
} c_entry;

// Build the counter from the *nums array.
void build_counter(c_entry **counter, int *nums, int numsLen) {
  for (int i = 0; i < numsLen; i++) {
    c_entry *s;
    HASH_FIND_INT(*counter, &nums[i], s);
    if (s) {
      // Increase freq:
      s->freq++;
    } else {
      // Add it with frequency 1.
      s = malloc(sizeof(*s));
      s->value = nums[i];
      s->freq = 1;
      HASH_ADD_INT(*counter, value, s);
    }
  }
}

// First sort through vfreqs:
int firstPass(const void *x, const void *y) {
  const int(*a)[3] = x;
  const int(*b)[3] = y;

  if ((*a)[0] < (*b)[0])
    return -1;

  if ((*a)[0] > (*b)[0])
    return 1;
  return 0;
}

// Second sort through vfreqs, reversed.
int secondPass(const void *x, const void *y) {
  const int(*a)[3] = x;
  const int(*b)[3] = y;

  if ((*b)[1] < (*a)[1])
    return -1;
  if ((*b)[1] > (*a)[1])
    return 1;
  return (*a)[2] >= (*b)[2];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *frequencySort(int *nums, int numsSize, int *returnSize) {
  c_entry *counter = NULL;
  build_counter(&counter, nums, numsSize);

  int size = HASH_COUNT(counter);
  int vfreqs[size][3], // NOLINT(clang-analyzer-core.VLASize)
      length = 0;
  // Build array from counter.
  c_entry *cur_e, *tmp;
  HASH_ITER(hh, counter, cur_e, tmp) {
    vfreqs[length][0] = cur_e->value;
    vfreqs[length++][1] = cur_e->freq;
    HASH_DEL(counter, cur_e);
  };
  // Sort vfreqs with two passes
  qsort(vfreqs, size, sizeof(vfreqs[0]), &firstPass);
  // Add position for tie-bracking.
  for (int i = 0; i < size; i++) {
    vfreqs[i][2] = i;
  }
  // Second pass.
  qsort(vfreqs, size, sizeof(vfreqs[0]), &secondPass);

  // Go through backwards and build result.
  int *result = malloc(numsSize * sizeof(*result)), pos = 0;
  for (int i = size - 1; i >= 0; i--) {
    int value = vfreqs[i][0], freqs = vfreqs[i][1];
    for (int k = 0; k < freqs; k++)
      result[pos++] = value;
  }
  *returnSize = numsSize;
  return result;
}
