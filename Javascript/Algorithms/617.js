/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
let mergeTrees = (t1, t2) => {
    // Check initial edge cases.
    if ((!t1) && (!t2)){
        return null;
    }
    if (!t1){
        return t2;
    }
    if (!t2){
        return t1;
    }
    let root = new TreeNode(t1.val + t2.val);
    // Supplied by leetcode.
    let q = new Queue();
    q.enqueue([root, t1.left, t1.right, t2.left, t2.right]);
    while (q.size()){
        let [r, l1, r1, l2, r2] = q.dequeue();
        // Empty branches => empty child.
        if ((!l1) && (!l2)){
            r.left = null;
        // Both brances valid => add values.
        } else if (l1 && l2) {
            r.left = new TreeNode(l1.val + l2.val);
            q.enqueue([r.left, l1.left, l1.right, l2.left, l2.right]);
        // Only one valid => attach it.
        } else {
            if (l1) {
                r.left = new TreeNode(l1.val, l1.left, l1.right);
            } else {
                r.left = new TreeNode(l2.val, l2.left, l2.right);
            }
        }
        // Empty branches => empty child.
        if ((!r1) && (!r2)){
            r.right = null;
        // Both branches valid => add values.
        } else if (r1 && r2) {
            r.right = new TreeNode(r1.val + r2.val);
            q.enqueue([r.right, r1.left, r1.right, r2.left, r2.right]);
        // Only one valid => attach it.
        } else {
            if (r1) {
                r.right = new TreeNode(r1.val, r1.left, r1.right);
            } else {
                r.right = new TreeNode(r2.val, r2.left, r2.right);
            }
        }        
    }
    return root;
};
