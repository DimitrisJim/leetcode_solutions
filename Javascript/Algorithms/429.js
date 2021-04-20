/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number[][]}
 */
let levelOrder = root => {
  if (!root) return [];
  const results = [], identity = x => x;

  const recurse = (node, level) => {
    if (level >= results.length)
      results.push([node.val]);
    else
      results[level].push(node.val);

    level++;
    for (let child of node.children.filter(identity)) recurse(child, level);
  };
  recurse(root, 0);
  return results;
};