#include <stdlib.h>

// Would like to only use node.val as key but nowhere in the
// description does it say if it is unique.
struct hash_entry {
  struct Node *n;    /* Only care about keys */
  UT_hash_handle hh; /* Makes this structure hashable */
};

int has_value(struct hash_entry *seen, struct Node *node) {
  struct hash_entry *s;
  HASH_FIND_PTR(seen, &node, s); /* node already in the hash? */
  return s == NULL ? 0 : 1;
}

void delete_all(struct hash_entry *seen) {
  struct hash_entry *current_node, *tmp;

  HASH_ITER(hh, seen, current_node, tmp) {
    HASH_DEL(seen, current_node); /* delete; users advances to next */
    free(current_node);           /* optional- if you want to free  */
  }
}

int *postorder(struct Node *root, int *returnSize) {
  // Edge case of empty root.
  if (!root) {
    *returnSize = 0;
    return (int *)NULL;
  }

  int size = 0, stackSize = 1, alloced_size = 50;
  // Initialize stack holding only root.
  struct Node **stack = malloc(1 * sizeof(*stack));
  stack[0] = root;
  // Initialize result array and seen hash table.
  int *res = malloc(alloced_size * sizeof(*res));
  struct hash_entry *seen = NULL;

  while (stackSize) {
    // peek value
    struct Node *node = stack[stackSize - 1];
    if (has_value(seen, node)) {
      stackSize--; // i.e pop of stack
      // resize if necessary and add node.val
      if (size == alloced_size) {
        alloced_size *= 1.5;
        res = realloc(res, alloced_size * sizeof(*res));
      }
      res[size++] = node->val;
    } else {
      // Add children if they exist.
      if (node->children) {
        int nc = node->numChildren;
        stack = realloc(stack, (stackSize + nc) * sizeof(*stack));
        for (int i = nc - 1; i >= 0; i--)
          stack[stackSize++] = node->children[i];

        // Since it has kids, add node to seen.
        struct hash_entry *s = malloc(sizeof(*s));
        s->n = node;
        HASH_ADD_PTR(seen, n, s);

      }
      // and if it doesn't (leaf), add to result.
      else {
        stackSize--;
        // resize if necessary.
        if (size == alloced_size) {
          alloced_size *= 1.5;
          res = realloc(res, alloced_size * sizeof(*res));
        }
        res[size++] = node->val;
      }
    }
  }
  free(stack);
  delete_all(seen);
  *returnSize = size;
  return res;
}
