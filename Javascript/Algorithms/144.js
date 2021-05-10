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
var preorderTraversal = function(root) {
  if (!root) return [];

  const values = [], stack = [root];
  while (stack.length > 0) {
    let node = stack.pop();

    values.push(node.val);
    let [left, right] = [node.left, node.right];
    // Push left second so we pop it first.
    if (right) stack.push(right);
    if (left) stack.push(left);
  }
  return values;
};