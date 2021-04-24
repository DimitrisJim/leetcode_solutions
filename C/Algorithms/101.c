bool traverse(struct TreeNode *left, struct TreeNode *right) {
  // Check value and bail if different.
  if (left->val != right->val)
    return false;

  // Get left,right for each and recurse symmetrically.
  struct TreeNode *lleft = left->left, *lright = left->right;
  struct TreeNode *rleft = right->left, *rright = right->right;

  // Hold results for each recursion.
  bool resa = true, resb = true;
  // Both need to be valid or NULL.
  if (lleft && rright)
    resa = traverse(lleft, rright);
  else {
    if (lleft != rright)
      return false;
  }
  if (lright && rleft)
    resb = traverse(lright, rleft);
  else {
    if (lright != rleft)
      return false;
  }
  // Both must be true for the tree to be symmetric.
  return resa && resb;
}

bool isSymmetric(struct TreeNode *root) {
  struct TreeNode *left = root->left, *right = root->right;
  // If both are valid, recurse. Else, if they're different,
  // directly return false (and if both are NULL, trivial case, return true.)
  if (right && left)
    return traverse(left, right);
  if (left != right)
    return false;
  return true;
}