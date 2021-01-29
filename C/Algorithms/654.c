#include <stdlib.h>

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode Node;

Node *build_tree(int *nums, int start, int end) {
  int max = *(nums + start), id = start;
  for (int i = start + 1; i < end; i++) {
    int v = *(nums + i);
    if (v > max) {
      max = v;
      id = i;
    }
  }

  // Go left and right:
  Node *left = NULL, *right = NULL;
  if (id > start)
    left = build_tree(nums, start, id);
  if (end > id + 1)
    right = build_tree(nums, id + 1, end);

  Node *n = malloc(sizeof(*n));
  n->val = max;
  n->left = left;
  n->right = right;
  return n;
}

Node *constructMaximumBinaryTree(int *nums, int numsSize) {
  return build_tree(nums, 0, numsSize);
}
