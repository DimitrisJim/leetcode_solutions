/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
  const visited = Array(101);
  const clone = node => {
    if (visited[node.val]) return visited[node.val];
    let neighbors = [];
    // pass ref to neighbors over to new node.
    let n = new Node(node.val, neighbors);
    visited[n.val] = n;
    node.neighbors.forEach(neighbor => neighbors.push(clone(neighbor)));
    return n;
  };
  return node ? clone(node) : null;
};