// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
  if (!root)
    return 0;

  // is there a way for it to be tail recursive
  // w/o calling it twice in the end?
  int da = maxDepth(root->left), dr = maxDepth(root->right);
  return da > dr ? da + 1 : dr + 1;
}
