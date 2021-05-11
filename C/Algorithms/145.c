/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode *node, int **values, int *length, int *size) {
  // Go left first.
  if (node->left)
    traverse(node->left, values, length, size);

  if (node->right)
    traverse(node->right, values, length, size);

  if ((*length + 1) >= *size) {
    *size *= 2;
    *values = realloc(*values, *size * sizeof(*values));
  }
  (*values)[(*length)++] = node->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
  *returnSize = 0;
  if (!root) {
    return NULL;
  }

  int size = 1;
  int *values = malloc(size * sizeof(int));
  traverse(root, &values, returnSize, &size);

  return values;
}