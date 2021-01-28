//  Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode Node;

void dfs_inorder(Node *node, int *s) {
  Node *left = node->left, *right = node->right;

  // Recurse right, alters right->val and sets s
  // pointer to new value.
  if (right) {
    dfs_inorder(right, s);
  }
  // Update node value.
  node->val += *s;
  if (left) {
    // Recurse with s set to new node-val and then set s
    // to whatever val has been altered to.
    int val = node->val;
    dfs_inorder(left, &val);
    *s = val;
  } else {
    // Else, just set it to node->val
    *s = node->val;
  }
}

struct TreeNode *bstToGst(struct TreeNode *root) {
  if (root) {
    int s = 0;
    dfs_inorder(root, &s);
  }
  return root;
}
