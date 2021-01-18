/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} t
 * @return {string}
 */
let tree2str = t => {
    let preorder = n => {
        const {val, left, right} = n;
        let s = `${val}`;
        if (left)
            s = [s, '(', preorder(left), ')'].join("");
        else {
            if (right)
                s = [s, '()'].join("");
        }
        if (right)
            s = [s, '(', preorder(right), ')'].join("");
        return s;
    }
    if (t)
        return preorder(t);
    return "";
};
