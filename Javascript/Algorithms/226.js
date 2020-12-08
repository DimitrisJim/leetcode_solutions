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
 * @return {TreeNode}
 */
let invert = (node) => {
    if (!node){
        return;
    }
    let tmp = node.right;
    node.right = node.left;
    node.left = tmp;
    return invert(node.left), invert(node.right);
}

var invertTree = function(root) {
    if (!root){
        return null;
    }
    invert(root);
    return root;
};
