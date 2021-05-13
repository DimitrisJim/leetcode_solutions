/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPath(struct TreeNode *node, int currentSum, int targetSum) {
  struct TreeNode *left = node->left, *right = node->right;
  // If at leaf and sums match, return.
  if ((!left) && (!right) && currentSum == targetSum)
    return true;

  // else, recurse on children.
  if (left) {
    if (hasPath(left, currentSum + left->val, targetSum))
      return true;
  }
  if (right) {
    if (hasPath(right, currentSum + right->val, targetSum))
      return true;
  }
  return false;
}

bool hasPathSum(struct TreeNode *root, int targetSum) {
  return root ? hasPath(root, root->val, targetSum) : false;
}