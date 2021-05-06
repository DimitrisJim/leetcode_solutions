/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool nodes_match(struct TreeNode *node1, struct TreeNode *node2) {
  if (node1->val != node2->val)
    return false;

  // extract children;
  struct TreeNode *left1 = node1->left, *right1 = node1->right;
  struct TreeNode *left2 = node2->left, *right2 = node2->right;

  bool result = true;
  if (left1 && left2)
    result = nodes_match(left1, left2);
  else
    result = (!left1) && (!left2);
  if (right1 && right2)
    return result && nodes_match(right1, right2);
  return result && (!right1) && (!right2);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot) {
  // Check subtree equality if values match.
  if (root->val == subRoot->val) {
    if (nodes_match(root, subRoot))
      return true;
  }

  struct TreeNode *left = root->left, *right = root->right;
  bool result = false;
  if (left)
    result = isSubtree(left, subRoot);
  if (right)
    return result || isSubtree(right, subRoot);
  return result;
}