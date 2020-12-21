#include "uthash/src/uthash.h"

typedef struct {
  int key;
  int value;
  UT_hash_handle hh;
} c_entry;

int findLucky(int *arr, int arrSize) {
  c_entry *Counter = NULL;

  for (int i = 0; i < arrSize; i++) {
    int key = arr[i];
    c_entry *e;
    HASH_FIND_INT(Counter, &key, e);
    if (e == NULL) {
      e = malloc(sizeof(*e));
      e->value = 1;
      e->key = key;
      HASH_ADD_INT(Counter, key, e);
    } else
      e->value++;
  }

  int largest = -1;
  c_entry *s;
  for (s = Counter; s != NULL; s = s->hh.next) {
    int key = s->key, value = s->value;
    if (key == value && key > largest) {
      largest = key;
    }
  }
  HASH_CLEAR(hh, Counter);
  return largest;
}
