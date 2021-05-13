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
 * @return {boolean}
 */
var isBalanced = function(root) {
  const cache = new Map, max = Math.max, abs = Math.abs;
  const height = (node) => {
    if (!node) return 0;

    // Check if cache contains node, else compute height and store.
    if (cache.has(node)) return cache[node];
    cache[node] = max(height(node.left), height(node.right)) + 1;
    return cache[node];
  }, recurse = (node) => {
    if (!node) return true;
    // children must also satisfy constraint.
    if (!(recurse(node.left) && recurse(node.right))) return false;
    // constraint: |height(left) - height(right)| <= 1
    return abs(height(node.left) - height(node.right)) <= 1;
  };
  return recurse(root);
};