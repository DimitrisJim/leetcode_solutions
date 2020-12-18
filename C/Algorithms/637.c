#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Make life a little easier.
typedef struct TreeNode node;

// Use some global state because I'm too bored to create
// a separate queue for this. Note, they could also
// be passed as pointers, alternatively.
static long *counts = NULL, *values = NULL, SIZE = 3;

void breadth(node *n, int level) {
  if (!n)
    return;

  if (level == SIZE) {
    SIZE++;
    counts = realloc(counts, SIZE * sizeof(*counts));
    values = realloc(values, SIZE * sizeof(*values));
    counts[SIZE - 1] = 0;
    values[SIZE - 1] = 0;
  }
  node *left = n->left, *right = n->right;
  values[level] += n->val;
  counts[level] += 1;

  if (left) {
    breadth(left, level + 1);
  }
  if (right) {
    breadth(right, level + 1);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double *averageOfLevels(node *root, int *returnSize) {
  counts = calloc(SIZE, sizeof(*counts));
  values = calloc(SIZE, sizeof(*values));
  breadth(root, 0);

  double *result = malloc(SIZE * sizeof(*result));
  int length = 0;
  for (int i = 0; i < SIZE; i++) {
    if (counts[i] != 0)
      result[length++] = (double)values[i] / counts[i];
  }
  free(counts);
  free(values);
  *returnSize = length;
  return result;
}
