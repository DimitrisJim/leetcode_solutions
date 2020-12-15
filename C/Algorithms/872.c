#include <stdbool.h>
#include <stdlib.h>

// sizeof for array in struct flagged as suspicious..
#define MAYBE_REALLOC(ptr, size, len)                                          \
  if (len + 1 >= size) {                                                       \
    size *= 1.5;                                                               \
    ptr = realloc(ptr, size * sizeof(*ptr));                                   \
  }

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Hold stuff for recursing.
typedef struct {
  struct TreeNode **arr;
  int length;
  int size;
} stack;

int next_leaf(stack *st) {
  //  The idea: Call continuously from outside with stack
  // constantly shifting. Return always returns some leaf.
  while (st->length) {
    struct TreeNode *node = st->arr[--(st->length)];
    if (!node->left && !node->right) {
      return node->val;
    }
    if (node->right) {
      MAYBE_REALLOC(st->arr, st->size, st->length);
      st->arr[st->length++] = node->right;
    }
    if (node->left) {
      MAYBE_REALLOC(st->arr, st->size, st->length);
      st->arr[st->length++] = node->left;
    }
  }
  return -1;
}

// Initialize stack struct.
stack *make_stack(int size, struct TreeNode *initval) {
  stack *s1 = malloc(sizeof(*s1));
  s1->arr = malloc(size * sizeof(*s1->arr));
  s1->size = size;
  s1->arr[0] = initval;
  s1->length = 1;

  return s1;
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
  // Make with initial sizes of power of 2.
  stack *s1 = make_stack(8, root1);
  stack *s2 = make_stack(8, root2);
  bool result = false;

  // Go through leaves and compare:
  while (1) {
    int l1 = next_leaf(s1), l2 = next_leaf(s2);
    if (l1 != l2)
      break;
    // reached end. break and return.
    if (l1 == -1 && l2 == -1) {
      result = true;
      break;
    }
  }

  // Free stuff and return.
  free(s1->arr), free(s2->arr);
  free(s1), free(s2);
  return result;
}
