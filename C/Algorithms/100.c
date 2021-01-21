#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode node;

bool traverse(node *n1, node *n2) {
  if (n1->val != n2->val)
    return false;

  node *n1left = n1->left, *n1right = n1->right;
  node *n2left = n2->left, *n2right = n2->right;
  bool res = true;
  // Bail early if one is None and the other isn't
  if (n1left) {
    if (!n2left)
      return false;
    res = res && traverse(n1left, n2left);
  } else {
    if (n2left)
      return false;
  }
  if (n1right) {
    if (!n2right)
      return false;
    res = res && traverse(n1right, n2right);
  } else {
    if (n2right)
      return false;
  }
  return res;
}

bool isSameTree(node *p, node *q) {
  if (!q && !p)
    return true;
  if ((!q && p) || (q && !p))
    return false;
  return traverse(p, q);
}
