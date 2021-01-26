#include "uthash/src/uthash.h"
#include <stdlib.h>

typedef struct {
  int *values, length;
} group;

typedef struct {
  int size;
  group *g;
  UT_hash_handle hh;
} d_entry;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **groupThePeople(int *groupSizes, int groupSizesSize, int *returnSize,
                     int **returnColumnSizes) {
  d_entry *d = NULL;
  // Initialize return structures.
  int resSize = 5, resLength = 0;
  int **result = malloc(resSize * sizeof(*result));
  *returnColumnSizes = malloc(resSize * sizeof(**returnColumnSizes));

  for (int i = 0; i < groupSizesSize; i++) {
    int group_i = groupSizes[i];
    // If group size is one, add immediately.
    if (group_i == 1) {
      // realloc if necessary.
      if (resLength + 1 == resSize) {
        resSize *= 2;
        result = realloc(result, resSize * sizeof(*result));
        *returnColumnSizes =
            realloc(*returnColumnSizes, resSize * sizeof(**returnColumnSizes));
      }
      int *grp = malloc(sizeof(*grp));
      grp[0] = i;
      result[resLength] = grp;
      (*returnColumnSizes)[resLength++] = 1;
      continue;
    }

    // Get group from map.
    d_entry *r;
    HASH_FIND_INT(d, &group_i, r);
    // We have a group.
    if (r) {
      group *g = r->g;
      // Grab values from group.
      if (g->length == group_i) {
        // realloc if necessary.
        if (resLength + 1 == resSize) {
          resSize *= 2;
          result = realloc(result, resSize * sizeof(*result));
          *returnColumnSizes = realloc(*returnColumnSizes,
                                       resSize * sizeof(**returnColumnSizes));
        }
        result[resLength] = g->values;
        (*returnColumnSizes)[resLength++] = group_i;
        // Re-initialize group values.
        int *values = malloc(group_i * sizeof(*values)), length = 0;
        values[length++] = i;
        g->values = values;
        g->length = length;
        // Just add to group.
      } else {
        g->values[g->length++] = i;
      }
      // New group, need to initialize.
    } else {
      // Initialize values.
      int *values = malloc(group_i * sizeof(*values)), length = 0;
      values[length++] = i;
      // group
      group *g = malloc(sizeof(*g));
      g->values = values;
      g->length = length;
      // and d_entry
      r = malloc(sizeof(*r));
      r->g = g;
      r->size = group_i;
      HASH_ADD_INT(d, size, r);
    }
  }

  // Need to add any groups still in d.
  d_entry *cur, *tmp;
  HASH_ITER(hh, d, cur, tmp) {
    group *g = cur->g;
    // realloc if necessary.
    if (resLength + 1 == resSize) {
      resSize *= 2;
      result = realloc(result, resSize * sizeof(*result));
      *returnColumnSizes =
          realloc(*returnColumnSizes, resSize * sizeof(**returnColumnSizes));
    }
    result[resLength] = g->values;
    // size will be equal to length.
    (*returnColumnSizes)[resLength++] = g->length;
    // free memory.
    HASH_DEL(d, cur);
    free(cur->g);
    free(cur);
  }

  // Clear map and return.
  HASH_CLEAR(hh, d);
  *returnSize = resLength;
  return result;
}
