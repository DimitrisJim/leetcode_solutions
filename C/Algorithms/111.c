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
 * @return {number}
 */
let minDepth = (root) = > {
  let min_depth = 10000000;
  const recurse = (node, depth) = > {
    // Don't recurse if we're at a deeper level.
    if (depth >= min_depth)
      return;

    let left = node.left, right = node.right;
    // Save depth if on leaf
    if (!left && !right) {
      min_depth = depth;
    } else {
      if (left)
        recurse(left, depth + 1, min_depth);
      if (right)
        recurse(right, depth + 1, min_depth);
    }
  };

  if (!root)
    return 0;
  recurse(root, 1);
  return min_depth;
};