/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function(root, targetSum) {
  if (!root) return [];
  let paths = [];
  const findPaths = (node, currentSum, level, path) => {
    if (level++ <= path.length) path = path.slice(0, level);
    path.push(node.val);

    const left = node.left, right = node.right;
    // If at leaf and sums match, return.
    if ((!left) && (!right) && currentSum == targetSum) paths.push(path);

    // else, recurse on children.
    if (left) findPaths(left, currentSum + left.val, level, path);
    if (right) findPaths(right, currentSum + right.val, level, path);
  }; 
  findPaths(root, root.val, 0, []);
  return paths;
};