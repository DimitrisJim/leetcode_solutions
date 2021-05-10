/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(node) {
  const stack = [], values = [];
  while (stack.length > 0 || node) {
    // keep going left until possible.
    if (node) {
      stack.push(node);
      node = node.left;
    } else {
      // pop left and go right
      node = stack.pop();
      values.push(node.val);
      node = node.right;
    }
  }
  return values;
};