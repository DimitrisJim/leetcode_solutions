// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode Node;

int traverse_sum(Node *node, int parent) {
  int sum = 0, val = node->val;
  Node *left = node->left, *right = node->right;

  // If left, add left val to sum and then add
  // whatever sum we get from recursing on left.
  // Similarly for right.
  if (left) {
    if ((parent & 1) == 0)
      sum += left->val;
    sum += traverse_sum(left, val);
  }
  if (right) {
    if ((parent & 1) == 0)
      sum += right->val;
    sum += traverse_sum(right, val);
  }
  return sum;
}

int sumEvenGrandparent(Node *root) {
  int val = root->val, sum = 0;
  Node *left = root->left, *right = root->right;
  // Call directly on children of root so we can
  // pass root val.
  if (left)
    sum += traverse_sum(left, val);
  if (right)
    sum += traverse_sum(right, val);
  return sum;
}
