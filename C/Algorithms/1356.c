#include <stdlib.h>

// Used in order to make qsort sort ascending when two values
// have same number of bits (stable).
typedef struct {
  int value;
  int order;
} entry;

// Compare values.
int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

// See: https://stackoverflow.com/a/109117
int countBitsSet(int i) {
  unsigned x = (unsigned)i;
  x = x - ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x0000003F;
}

// Compare entries. If the bit difference is the same,
// use the order to pick winner.
int cmpe(const void *x, const void *y) {
  entry *a = (entry *)x;
  entry *b = (entry *)y;

  int diff = countBitsSet(a->value) - countBitsSet(b->value);
  return diff != 0 ? diff : a->order - b->order;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortByBits(int *arr, int arrSize, int *returnSize) {
  // Initial sort.
  qsort(arr, arrSize, sizeof(*arr), cmpi);

  // Initialize temp.
  entry *temp = malloc(arrSize * sizeof(*temp));
  for (int i = 0; i < arrSize; i++)
    temp[i] = (entry){arr[i], i};

  // Sort entries array and re-assign values.
  qsort(temp, arrSize, sizeof(temp[0]), cmpe);
  for (int i = 0; i < arrSize; i++)
    arr[i] = temp[i].value;

  // Free and return.
  free(temp);
  *returnSize = arrSize;
  return arr;
}
