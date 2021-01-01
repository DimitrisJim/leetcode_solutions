#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode node;

node *build_tree(int *nums, int left, int right) {
  if (left == right) {
    return NULL;
  }
  int mid = (left + right) / 2;
  node *n = malloc(sizeof(*n));
  n->val = nums[mid];

  // fill left, right
  n->left = build_tree(nums, left, mid);
  n->right = build_tree(nums, mid + 1, right);

  return n;
}

node *sortedArrayToBST(int *nums, int numsSize) {
  return build_tree(nums, 0, numsSize);
}
