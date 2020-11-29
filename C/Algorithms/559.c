// Definition for a Node.
struct Node {
  int val;
  int numChildren;
  struct Node **children;
};

int depth(struct Node *root) {
  // base case.
  if (root->numChildren == 0)
    return 1;
  // recurse.
  int max = 0;
  for (int i = 0; i < root->numChildren; i++) {
    int value = depth(root->children[i]);
    if (value > max) {
      max = value;
    }
  }
  return max + 1;
}

int maxDepth(struct Node *root) {
  if (!root) {
    return 0;
  }
  return depth(root);
}
