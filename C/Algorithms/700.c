#include <stdlib.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// iterative version.
struct TreeNode *searchBST(struct TreeNode *root, int val) {
  while (root) {
    int rval = (*root).val;
    if (rval == val)
      return root;
    root = val > rval ? (*root).right : (*root).left;
  }
  return NULL;
}

// tail-recursive version.
struct TreeNode *_searchBST(struct TreeNode *root, int val) {
  if (!root)
    return NULL;
  int rval = (*root).val;
  if (rval == val)
    return root;
  return searchBST(val > rval ? (*root).right : (*root).left, val);
}
