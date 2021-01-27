// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode Node;

void traverse_add(Node *node, int current_depth, int *max_depth, int *l_sum) {
  Node *left = node->left, *right = node->right;

  // See if we need to add to l_sum and increase depth when we reach leaf.
  if (!left && !right) {
    if (current_depth > *max_depth) {
      *l_sum = node->val;
      *max_depth = current_depth;
    } else if (current_depth == *max_depth)
      *l_sum += node->val;
  } else {
    if (left)
      traverse_add(left, current_depth + 1, max_depth, l_sum);
    if (right)
      traverse_add(right, current_depth + 1, max_depth, l_sum);
  }
}

int deepestLeavesSum(struct TreeNode *root) {
  int l_sum = 0, max_depth = 0;
  // Pass pointers to keep track of l_sum, max_depth.
  traverse_add(root, 0, &max_depth, &l_sum);
  return l_sum;
}
