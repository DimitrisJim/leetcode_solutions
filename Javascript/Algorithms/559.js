/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number}
 */
let maxDepth = root => {
    let depth = node => {
        if (node.children.length == 0){
            return 1;
        }
        return 1 + _.max(node.children.map((n) => depth(n)));
    }
    return root ? depth(root) : 0;
};
