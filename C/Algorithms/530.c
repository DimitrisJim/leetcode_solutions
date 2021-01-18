#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode node;

// Fill up an array during dfs traversal.
void traverse(node *n, int **buf, int *buflen, int *bufsize) {
  node *left = n->left, *right = n->right;
  if (left) {
    traverse(left, buf, buflen, bufsize);
  }
  if ((*buflen + 1) >= (*bufsize)) {
    *bufsize = *bufsize * 2;
    *buf = realloc(*buf, (*bufsize) * sizeof(**buf));
  }
  (*buf)[(*buflen)++] = n->val;
  if (right) {
    traverse(right, buf, buflen, bufsize);
  }
}

int getMinimumDifference(node *root) {
  // Use a power of 2 for size.
  // Without a hint we can use, 32 seems to work ok.
  int size = 32, length = 0;
  int *nodes = malloc(size * sizeof(*nodes));
  // Fills nodes with node values in sorted order (due to BST prop).
  traverse(root, &nodes, &length, &size);

  // Set an initial value for min based on root-left or right-root.
  int min =
      root->left ? root->val - root->left->val : root->right->val - root->val;
  // Go through values and find min diff.
  for (int i = 1; i < length; i++) {
    int diff = nodes[i] - nodes[i - 1];
    if (diff < min)
      min = diff;
  }
  free(nodes);
  return min;
}
