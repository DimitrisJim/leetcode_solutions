#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode *node) {
  int size = 4, length = 0, value = node->val;
  struct TreeNode **stack = malloc(sizeof(*stack) * size);
  stack[length++] = node;
  while (length > 0) {
    node = stack[--length];
    struct TreeNode *left = node->left, *right = node->right;
    if (right) {
      if (right->val != value) {
        free(stack);
        return false;
      }
      if (length == size) {
        size *= 1.5;
        stack = realloc(stack, size * sizeof(*stack));
      }
      stack[length++] = right;
    }
    if (left) {
      if (left->val != value) {
        free(stack);
        return false;
      }
      if (length == size) {
        size *= 1.5;
        stack = realloc(stack, size * sizeof(*stack));
      }
      stack[length++] = left;
    }
  }
  free(stack);
  return true;
}
