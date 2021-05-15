/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
void recursive_connect(struct Node *node) {
  struct Node *left = node->left, *right = node->right;
  // If both exist, link left to right. Else, leaf, return.
  if (left && right)
    left->next = right;
  else if (!left && !right) {
    return;
  }

  if (node->next) {
    struct Node *uncle = node->next;
    (right ? right : left)->next = (uncle->left ? uncle->left : uncle->right);
  }

  if (left)
    recursive_connect(left);
  if (right)
    recursive_connect(right);
}

struct Node *connect(struct Node *root) {
  if (!root)
    return NULL;
  recursive_connect(root);
  return root;
}