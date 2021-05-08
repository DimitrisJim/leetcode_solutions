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
var rightSideView = function(root) {
  if (!root) return [];

  const nodes = [root.val], stack = [[root, 0]];

  while (stack.length > 0) {
    let [node, level] = stack.pop();

    // Push the first node we encounter on next level (which
    // we know due to our pushing on the stack, will be the
    // rightmost node in tree.)
    if (level >= nodes.length) {
      nodes.push(node.val);
    }

    // Push right *last*, that way we see it *first*.
    let left = node.left, right = node.right;
    if (left) {
      stack.push([left, level + 1]);
    }
    if (right) {
      stack.push([right, level + 1]);
    }
  }
  return nodes;
};