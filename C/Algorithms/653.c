#include "uthash/src/uthash.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int key;
  UT_hash_handle hh;
} cache_t;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool traverse(struct TreeNode *n, int k, cache_t **seen) {
  cache_t *tmp;
  int diff = k - n->val;
  HASH_FIND_INT(*seen, &diff, tmp);
  if (tmp) {
    return true;
  } else {
    tmp = malloc(sizeof(*tmp));
    tmp->key = n->val;
    HASH_ADD_INT(*seen, key, tmp);
  }

  if (n->left) {
    if (traverse(n->left, k, seen))
      return true;
  }
  if (n->right) {
    if (traverse(n->right, k, seen))
      return true;
  }
  return false;
}

bool findTarget(struct TreeNode *root, int k) {
  cache_t *seen = NULL;
  bool res = traverse(root, k, &seen);
  HASH_CLEAR(hh, seen);
  return res;
}
