#include <stdlib.h>

/**
 * Definition for a binary tree node. */
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define INIT_SIZE 10
// Should clean things up a bit.
#define SHOULD_RESIZE_ARRAY(arr, length, size)                                 \
  if (length == size - 1) {                                                    \
    size *= 1.5;                                                               \
    arr = realloc(arr, size * sizeof(*arr));                                   \
  }

int sumRootToLeaf(struct TreeNode *root) {
  // Initialize counters and arrays.
  int paths_len = 0, stack_len = 0;
  int paths_size = INIT_SIZE, stack_size = INIT_SIZE;
  int *paths = malloc(paths_size * sizeof(*paths));
  struct TreeNode **stack = malloc(stack_size * sizeof(*stack));

  stack[stack_len++] = root;
  while (stack_len) {
    struct TreeNode *node = stack[--stack_len];
    // Add to paths if we have no children..
    if (!node->left && !node->right) {
      SHOULD_RESIZE_ARRAY(paths, paths_len, paths_size);
      paths[paths_len++] = node->val;
      continue;
    }

    // Update val for right and add to stack.
    if (node->right) {
      node->right->val = (node->val << 1) | node->right->val;
      SHOULD_RESIZE_ARRAY(paths, paths_len, paths_size);
      stack[stack_len++] = node->right;
    }
    // Update val for left and add to stack.
    if (node->left) {
      node->left->val = (node->val << 1) | node->left->val;
      SHOULD_RESIZE_ARRAY(stack, stack_len, stack_size);
      stack[stack_len++] = node->left;
    }
  }
  // Don't need this anymore.
  free(stack);
  // Create the sum.
  int sum = 0;
  for (int i = 0; i < paths_len; i++)
    sum += paths[i];
  // Go away.
  free(paths);
  // Return sum.
  return sum;
}
