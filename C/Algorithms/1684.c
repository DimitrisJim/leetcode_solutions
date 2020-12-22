#include "uthash/src/uthash.h"

typedef struct {
  int value;
  UT_hash_handle hh;
} s_entry;

int countConsistentStrings(char *allowed, char **words, int wordsSize) {
  // create set of allowed characters.
  s_entry *allowed_set = NULL;
  while (*allowed) {
    s_entry *e = malloc(sizeof(*e));
    e->value = *allowed++;
    HASH_ADD_INT(allowed_set, value, e);
  }

  int count = 0, flag = 1;
  for (int i = 0; i < wordsSize; i++) {
    char *s = words[i];
    while (*s) {
      s_entry *e;
      int value = *s++;
      HASH_FIND_INT(allowed_set, &value, e);
      if (!e) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      flag = 1;
      continue;
    }
    count++;
  }
  HASH_CLEAR(hh, allowed_set);
  return count;
}
