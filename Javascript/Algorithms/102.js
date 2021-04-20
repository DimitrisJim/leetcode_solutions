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
 * @return {number[][]}
 */
let levelOrder = (root) => {
  if (!root) return [];

  const stack = [[root, 0]], results = [];
  while (stack.length > 0) {
    let [node, level] = stack.pop();

    if (level >= results.length)
      results.push([node.val]);
    else
      results[level].push(node.val);

    let left = node.left, right = node.right;
    if (right) stack.push([right, level + 1]);
    if (left) stack.push([left, level + 1]);
  }
  return results;
};