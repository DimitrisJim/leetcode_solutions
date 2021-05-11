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
var postorderTraversal = function(node) {
  // See wiki page for iterative traversal algorithm.
  // I, in general, don't remember iterative version by heart.
  const stack = [], values = [];
  let lastVisited = null;
  while (stack.length > 0 || node) {
    // keep going left until possible.
    if (node) {
      stack.push(node);
      node = node.left;
    } else if (stack.length > 0) {
      let [end] = stack.slice(-1);
      // go right, if it exists and it hasn't been
      // visited.
      if (end.right && end.right != lastVisited)
        node = end.right;
      else {
        values.push(end.val);
        lastVisited = stack.pop();
      }
    }
  }
  return values;
};