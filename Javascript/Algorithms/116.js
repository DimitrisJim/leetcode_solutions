/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
  const recursive_connect =
      node => {
        const left = node.left, right = node.right;
        // If both exist, link left to right. Else, leaf, return.
        if (left && right)
          left.next = right;
        else if (!left && !right) {
          return;
        }

        // Link right (or left, if right == null) to left (or right, if left ==
        // null) of uncle.
        if (node.next) {
          const uncle = node.next;
          if (right)
            right.next = (uncle.left ? uncle.left : uncle.right);
          else
            left.next = (uncle.left ? uncle.left : uncle.right);
        }

        if (left) recursive_connect(left);
        if (right) recursive_connect(right);
      }

  if (!root)
  return null;
  recursive_connect(root);
  return root;
};