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
let sumRootToLeaf = root => {
    let paths = [],
        stack = [root];
    while (stack[0]){
        let node = stack.pop();
        let val = node.val;
        if (!(node.left) && !(node.right)){
            paths.push(val);
            continue;
        }
        if (node.right){
            node.right.val = (val << 1) | node.right.val;
            stack.push(node.right);
        }
        if (node.left){
            node.left.val = (val << 1) | node.left.val;
            stack.push(node.left);
        }
    }
    // translate back to number
    return paths.reduce((acc, x) => acc + x);
};
