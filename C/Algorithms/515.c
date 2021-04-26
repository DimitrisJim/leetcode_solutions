/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void visit(struct TreeNode *node, int level, int **maxes, int *size) {
  int value = node->val;
  if (level >= *size) {
    *size = *size + 1;
    *maxes = realloc(*maxes, (*size) * sizeof(int));
    (*maxes)[level] = value;
  } else {
    int prev_max = (*maxes)[level];
    (*maxes)[level] = prev_max > value ? prev_max : value;
  }
  struct TreeNode *left = node->left, *right = node->right;
  if (left) {
    visit(left, level + 1, maxes, size);
  }
  if (right) {
    visit(right, level + 1, maxes, size);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *largestValues(struct TreeNode *root, int *returnSize) {
  *returnSize = 0;
  if (!root) {
    return NULL;
  }
  int *maxes = malloc(sizeof(int));
  visit(root, 0, &maxes, returnSize);
  return maxes;
}