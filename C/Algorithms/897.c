#include <stdlib.h>

#define GEO_PROG 1.5

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *increasingBST(struct TreeNode *root) {
  // Use floor(log2(100)) as init size for stack.
  // Use 20 for inorder. Arithmetic progression by 1.5 leads to a
  // nice size of 100 after 3 resizes.
  int stack_size = 6, inorder_size = 20;
  int stack_length = 0, inorder_length = 0;
  struct TreeNode **stack = malloc(stack_size * sizeof(*stack));
  // Hold nodes in an inorder order.
  struct TreeNode **inorder = malloc(inorder_size * sizeof(*inorder));

  while ((stack_length != 0) || root) {
    // go down left subtree.
    if (root) {
      // resize if we reach our limit.
      if (stack_length == (stack_size - 1)) {
        stack_size *= GEO_PROG;
        stack = realloc(stack, stack_size * sizeof(*stack));
      }
      stack[stack_length++] = root;
      root = root->left;
      // right subtree.
    } else {
      root = stack[--stack_length];
      root->left = NULL;
      // resize if we reach our limit.
      if (inorder_length == (inorder_size - 1)) {
        inorder_size *= GEO_PROG;
        inorder = realloc(inorder, inorder_size * sizeof(*inorder));
      }
      inorder[inorder_length++] = root;
      root = root->right;
    }
  }
  // Re-attach nodes:
  for (int i = inorder_length - 1; i > 0; i--)
    inorder[i - 1]->right = inorder[i];

  // Clean-up and return.
  struct TreeNode *res = inorder[0];
  free(inorder);
  free(stack);
  return res;
}
