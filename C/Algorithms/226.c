#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void invert(struct TreeNode *node) {
  // Base case: leaf, simply return.
  if (!node)
    return;

  // Do the switch and recurse on children.
  struct TreeNode *tmp = node->right;
  node->right = node->left;
  node->left = tmp;
  return invert(node->left), invert(node->right);
}

struct TreeNode *invertTree(struct TreeNode *root) {
  if (!root)
    return NULL;
  invert(root);
  return root;
}
