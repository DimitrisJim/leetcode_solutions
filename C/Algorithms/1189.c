#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int key;
  int count;
  UT_hash_handle hh;
} c_entry;

void count_values(c_entry **c, char *value) {
  int chr;
  while ((chr = *value++)) {
    c_entry *ne;
    HASH_FIND_INT(*c, &chr, ne);
    if (!ne) {
      // value not found.
      ne = malloc(sizeof(*ne));
      ne->key = chr;
      ne->count = 1;
      HASH_ADD_INT(*c, key, ne);
    } else {
      ne->count++;
    }
  }
}

int maxNumberOfBalloons(char *text) {
  c_entry *counter = NULL;
  char *word = "balloon";
  int size = 7, times = 0, chr;
  // Create a counter from the characters.
  count_values(&counter, text);

  // Continously reduce chars composing 'balloon' until
  // we can't anymore.
  while (1) {
    for (int i = 0; i < size; i++) {
      chr = word[i];
      c_entry *t;
      HASH_FIND_INT(counter, &chr, t);
      if (t) {
        if (t->count == 0)
          return times;
        t->count--;
      } else
        return times;
    }
    times++;
  }
  return times;
}
