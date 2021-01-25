/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */
let getTargetCopy = (original, cloned, target) => {
    const traverse = (node, val) => {
        if (node.val == val){
            return node;
        }
        let left = node.left, right = node.right;
        if (left){
            let n = traverse(left, val);
            if (n)
                return n;
        }
        if (right){
            let n = traverse(right, val);
            if (n)
                return n;
        }
    };
    return traverse(cloned, target.val);
};
