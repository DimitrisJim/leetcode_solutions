#include <stdlib.h>

#define DEFAULT 1000 // returned when we call 'get' on a key that doesn't exist.

typedef struct {
  int key;   // values of arr2 are keys
  int order; // their index in arr2 determines the order.
  UT_hash_handle hh;
} d_entry;

// Need it as global, can't see how else I can use it from cmpfunc
d_entry *order = NULL;

// Compare: get_order of both values and return as you normally would.
int cmpfunc(const void *x, const void *y) {
  int a_ = *(const int *)x, b_ = *(const int *)y;
  // Get order.
  d_entry *result;
  HASH_FIND_INT(order, &a_, result);
  int a = result ? result->order : DEFAULT + a_;
  HASH_FIND_INT(order, &b_, result);
  int b = result ? result->order : DEFAULT + b_;

  return (a > b) - (a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size,
                       int *returnSize) {
  // Add values to order mapping.
  for (int i = 0; i < arr2Size; i++) {
    // values are distinct, don't need to use FIND_INT first
    d_entry *entry = malloc(sizeof(*entry));
    entry->key = *(arr2 + i);
    entry->order = i;
    HASH_ADD_INT(order, key, entry);
  }
  // Sort and return.
  qsort(arr1, arr1Size, sizeof(*arr1), cmpfunc);
  HASH_CLEAR(hh, order);
  *returnSize = arr1Size;
  return arr1;
}
