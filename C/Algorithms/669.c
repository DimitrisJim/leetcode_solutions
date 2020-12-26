#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} node;

void trimmer(node *child, node *parent, int low, int high) {
  // Reached leaf, can't go anywhere.
  if (child == NULL)
    return;

  int value = (*child).val;
  node *left = (*child).left, *right = (*child).right;
  if (value < low) {
    // Go trimming left or right accordingly.
    (*parent).left = right;
    trimmer(right, parent, low, high);
  } else if (value > high) {
    (*parent).right = left;
    trimmer(left, parent, low, high);
  } else {
    // We're inside the acceptable range, recurse on children
    // with child as new parent.
    trimmer(left, child, low, high);
    trimmer(right, child, low, high);
  }
}

node *trimBST(node *root, int low, int high) {
  if (root == NULL) {
    return NULL;
  }
  int value = (*root).val;
  node *left = (*root).left, *right = (*root).right;
  // Re-adjust here instead of using global state to handle
  // changes of root.
  if (value < low) {
    root = right;
    return trimBST(root, low, high);
  } else if (value > high) {
    root = left;
    return trimBST(root, low, high);
  } else
    trimmer(root, NULL, low, high);
  return root;
}
