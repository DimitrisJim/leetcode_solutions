#include "uthash/src/uthash.h"
#include <stdbool.h>
#include <stdlib.h>

// Used for the map.
typedef struct {
  int key;
  int value;
  UT_hash_handle hh;
} m_entry;

void m_delete_all(m_entry *t) {
  m_entry *current_entry, *tmp;

  HASH_ITER(hh, t, current_entry, tmp) {
    HASH_DEL(t, current_entry); /* delete it */
  }
}

// Used for the set.
typedef struct {
  int val;
  UT_hash_handle hh;
} s_entry;

void s_delete_all(s_entry *s) {
  s_entry *current_entry, *tmp;

  HASH_ITER(hh, s, current_entry, tmp) {
    HASH_DEL(s, current_entry); /* delete it */
  }
}

bool uniqueOccurrences(int *arr, int arrSize) {
  m_entry *map = NULL;
  for (int i = 0; i < arrSize; i++) {
    int key = *(arr + i);
    // Adds key with value 1 if it doesn't already exist in the map
    // else increments value.
    m_entry *e;
    HASH_FIND_INT(map, &key, e); /* key already in the hash? */
    if (e == NULL) {
      e = malloc(sizeof *e);
      e->key = key;
      e->value = 1;
      HASH_ADD_INT(map, key, e);
    }
    e->value++;
  }
  // Iterate through map and build set.
  s_entry *set = NULL;
  for (m_entry *e = map; e != NULL; e = e->hh.next) {
    s_entry *s;
    HASH_FIND_INT(set, &e->value, s); /* val already in the hash? */
    if (s == NULL) {
      s = malloc(sizeof *s);
      s->val = e->value;
      HASH_ADD_INT(set, val, s);
    }
  }
  // Get lengths
  unsigned mcount = HASH_COUNT(map);
  unsigned scount = HASH_COUNT(set);
  // Free stuff.
  m_delete_all(map);
  s_delete_all(set);
  // same length?
  return mcount == scount;
}
