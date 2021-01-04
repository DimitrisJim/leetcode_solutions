#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  UT_hash_handle hh;
} s_entry;

void build_set(s_entry **set, int *arr, int arrSize) {
  s_entry *t;
  int value;
  for (int i = 0; i < arrSize; i++) {
    value = *(arr + i);
    HASH_FIND_INT(*set, &value, t);
    if (!t) {
      t = malloc(sizeof(*t));
      t->key = value;
      HASH_ADD_INT(*set, key, t);
    }
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *fairCandySwap(int *A, int ASize, int *B, int BSize, int *returnSize) {
  int *result = malloc(2 * sizeof(int));
  *returnSize = 2;

  int sumA = 0, sumB = 0;
  for (int i = 0; i < ASize; i++)
    sumA += *(A + i);
  for (int i = 0; i < BSize; i++)
    sumB += *(B + i);
  int a_larger = sumA > sumB;
  int diff = a_larger ? (sumA - sumB) / 2 : (sumB - sumA) / 2;

  int *max = NULL, *tmp = NULL, maxSize;
  s_entry *min = NULL;
  if (a_larger) {
    max = A;
    maxSize = ASize;
    build_set(&min, B, BSize);
  } else {
    max = B;
    maxSize = BSize;
    build_set(&min, A, ASize);
  }

  s_entry *t;
  int val, j;
  for (int i = 0; i < maxSize; i++) {
    val = *(max + i);
    j = val - diff;
    HASH_FIND_INT(min, &j, t);
    if (t) {
      HASH_CLEAR(hh, min);
      result[0] = a_larger ? val : j;
      result[1] = a_larger ? j : val;
      return result;
    }
  }
  HASH_CLEAR(hh, min);
  // unreachable.
  result[0] = 0;
  result[1] = 0;
  return result;
}
