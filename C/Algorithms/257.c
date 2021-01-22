#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef struct TreeNode Node;

char *join(int val, char *previous) {
  int valSize = snprintf(NULL, 0, "%d", val);
  if (!previous) {
    char *res = malloc(valSize + 1);
    snprintf(res, valSize + 1, "%d", val);
    return res;
  }

  // We add +2 to account for '->'.
  int prevSize = strlen(previous);
  char *res = malloc(prevSize + valSize + 3);

  // Copy previous until res, doesn't copy trailing '\0'
  memcpy(res, previous, prevSize);
  res[prevSize++] = '-';
  res[prevSize++] = '>';
  snprintf(res + prevSize, valSize + 1, "%d", val);
  return res;
}

void get_paths(Node *node, char *previous, char ***result, int *size,
               int *length) {
  // Build the path from previous and node->val.
  char *prev = join(node->val, previous);
  // Recurse with new previous on left/right.
  Node *left = node->left, *right = node->right;
  if (left) {
    get_paths(left, prev, result, size, length);
  }
  if (right) {
    get_paths(right, prev, result, size, length);
  }
  // Add to result array, reached leaf.
  if (!left && !right) {
    if ((*length + 1) == *size) {
      *size *= 1.5;
      *result = realloc(*result, *size * sizeof(**result));
    }
    // Copy pointer over.
    (*result)[(*length)++] = prev;
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
  // Start with best guess initial size multiple of 2.
  int size = 8, length = 0;
  char **result = malloc(size * sizeof(*result));

  if (root)
    get_paths(root, NULL, &result, &size, &length);
  *returnSize = length;
  return result;
}
