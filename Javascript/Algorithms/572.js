/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
var nodes_match =
    (node1, node2) => {
      if (node1.val != node2.val) return false;

      // extract children;
      const left1 = node1.left, right1 = node1.right, left2 = node2.left,
            right2 = node2.right;
      let result = true;

      if (left1 && left2)
        result = nodes_match(left1, left2);
      else
        result = (!left1) && (!left2);
      if (right1 && right2) return result && nodes_match(right1, right2);
      return result && (!right1) && (!right2);
    }

var isSubtree = function(root, subRoot) {
  // Check subtree equality if values match.
  if (root.val == subRoot.val) {
    if (nodes_match(root, subRoot)) return true;
  }

  const left = root.left, right = root.right;
  let result = false;
  if (left) result = isSubtree(left, subRoot);
  if (right) return result || isSubtree(right, subRoot);
  return result;
};