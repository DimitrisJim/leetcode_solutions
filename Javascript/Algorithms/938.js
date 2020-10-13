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
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
    // quick special cases.
    if (L == R)
        return L;
    if (root == null)
        return 0;
    
    // Adjust the root if needed.
    let val = root.val
    while (!((L <= val) && (val <= R))){
        if (val < L){
            root = root.right;
        } else {
            root = root.left;
        }
        val = root.val;
    }
    
    
    let inorder = function(root, L, R){
        let sum = 0;
        let {left, right, val} = root;
        if (left) 
            sum += inorder(left, L, R);

        if ((L <= val) && (val <= R))
            sum += val;

        if (right)
            sum += inorder(right, L, R);

        return sum;
    }    
    
    // Some additional special cases.
    if (val == R)
        return val + inorder(root.left, L, R); 
    if (val == L)
        return val + inorder(root.right, L, R);
    
    // go add elements found 
    return inorder(root, L, R);
};
