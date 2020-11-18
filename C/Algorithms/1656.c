#include "uthash/src/uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 6

// Hash structure.
struct ht {
  int id; /* key */
  char value[6];
  UT_hash_handle hh; /* makes this structure hashable */
};

typedef struct {
  int ptr;
  struct ht *table;
} OrderedStream;

OrderedStream *orderedStreamCreate(int n) {
  OrderedStream *o = malloc(sizeof(*o));
  o->ptr = 1;
  o->table = NULL;
  return o;
}

char **orderedStreamInsert(OrderedStream *obj, int id, char *value,
                           int *retSize) {
  // Keep track of allocated size and length
  int alloced_size = 2, length = 0;
  char **res = malloc(alloced_size * sizeof(*res));
  // Add to table.
  struct ht *s = malloc(sizeof(*s));
  s->id = id;
  strcpy(s->value, value);
  HASH_ADD_INT(obj->table, id, s);

  while (1) {
    // Get from the table based on ptr.
    struct ht *e;
    HASH_FIND_INT(obj->table, &obj->ptr, e);
    // if nothing, we're done.
    if (!e)
      break;
    // else, add it to result array and increment.
    if (length == (alloced_size - 1)) {
      alloced_size *= 2;
      res = realloc(res, alloced_size * sizeof(*res));
    }
    res[length] = malloc(STR_SIZE * sizeof(char));
    strcpy(res[length++], e->value);
    obj->ptr++;
  }
  *retSize = length;
  return res;
}

void free_table(struct ht *table) {
  struct ht *current_node, *tmp;
  // free everything.
  HASH_ITER(hh, table, current_node, tmp) {
    HASH_DEL(table, current_node);
    free(current_node);
  }
}

void orderedStreamFree(OrderedStream *obj) {
  if (obj) {
    free_table(obj->table);
    free(obj);
  }
}
