/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
let increasingBST = root => {
    let stack = [], inorder = [];
    while (stack.length || root) {
        // go down left subtree.
        if (root) {
            stack.push(root);
            root = root.left;
        // right subtree.
        } else {
            root = stack.pop();
            root.left = null;
            inorder.push(root);
            root = root.right;
        }
    }
    // Re-attach nodes:
    return inorder.reduceRight((acc, v) => (v.right = acc, v));
};
