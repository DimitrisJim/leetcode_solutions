#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode Node;

Node *build(int *vals, int start, int end) {
  if (start == end)
    return NULL;

  int val = vals[start];
  int max_min = start + 1;
  // find max val smaller than node.val (left subtree)
  while (max_min < end && vals[max_min] < val)
    max_min++;

  // fill left with vals < node.val and right with vals > node.val
  Node *node = malloc(sizeof(*node));
  node->val = val;
  node->left = build(vals, start + 1, max_min);
  node->right = build(vals, max_min, end);
  return node;
}

struct TreeNode *bstFromPreorder(int *preorder, int preorderSize) {
  return build(preorder, 0, preorderSize);
}
