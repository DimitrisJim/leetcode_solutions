#include <stdlib.h>

struct Node {
  int val;
  int numChildren;
  struct Node **children;
};

int *preorder(struct Node *root, int *returnSize) {
  // edge case -- bail early.
  if (!root) {
    *returnSize = 0;
    return NULL;
  }
  // Use a coarse initial size. Pretty sure could do the same
  // for stack but meh.
  int size = 0, stackSize = 1;
  int alloced_size = 50;
  struct Node **stack = malloc(1 * sizeof(*stack));
  int *res = malloc(alloced_size * sizeof(int));
  stack[0] = root;

  while (stackSize > 0) {
    // pop
    struct Node *node = stack[--stackSize];
    if ((*node).children) {
      // realloc stack to hold children.
      int nc = (*node).numChildren;
      stack = realloc(stack, (stackSize + nc) * sizeof(*stack));
      // Add children to stack.
      for (int i = nc - 1; i >= 0; i--)
        stack[stackSize++] = node->children[i];
    }
    if (size == alloced_size) {
      alloced_size *= 1.5;
      res = realloc(res, alloced_size * sizeof(int));
    }
    // Add to result.
    res[size++] = (*node).val;
  }
  *returnSize = size;
  free(stack);
  return res;
}
