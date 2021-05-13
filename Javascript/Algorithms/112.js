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
 * @param {number} targetSum
 * @return {boolean}
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
var hasPath =
    function(node, currentSum, targetSum) {
  const left = node.left, right = node.right;
  // If at leaf and sums match, return.
  if ((!left) && (!right) && currentSum == targetSum) return true;

  // else, recurse on children.
  if (left) {
    if (hasPath(left, currentSum + left.val, targetSum)) return true;
  }
  if (right) {
    if (hasPath(right, currentSum + right.val, targetSum)) return true;
  }
  return false;
}

var hasPathSum = function(root, targetSum) {
  return root ? hasPath(root, root.val, targetSum) : false;
};