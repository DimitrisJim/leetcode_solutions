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
let bstToGst = root => {
    const dfs_inorder = (node, s) => {
        const {val, left, right} = node;
        
        // Go right and accumulate value in s.
        if (right){
            let [nr, ns] = dfs_inorder(right, s);
            s = ns
            node.right = nr;
        }
        node.val = val + s;
        // Need to recurse into left and return accumulated value.
        // Need to *still* return node though (returning node.left)
        // would prune almost all of the right subtree.
        if (left){
            let [nl, ns] = dfs_inorder(left, node.val);
            node.left = nl;
            return [node, ns];
        }
        return [node, node.val];
    }

    if (root)
        return dfs_inorder(root, 0)[0];
    return root;
};
