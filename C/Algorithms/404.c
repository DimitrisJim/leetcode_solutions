void sum_left_leafs(struct TreeNode *node, int *sum) {
  struct TreeNode *left = node->left, *right = node->right;

  if (left)
    // Add to sum when we're in left child and
    // it's a leaf.
    if (!left->left && !left->right)
      *sum += left->val;
    else
      sum_left_leafs(left, sum);
  if (right)
    sum_left_leafs(right, sum);
}

int sumOfLeftLeaves(struct TreeNode *root) {
  int sum = 0;
  sum_left_leafs(root, &sum);
  return sum;
}