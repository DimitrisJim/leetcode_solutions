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
 * @return {boolean}
 */
let isUnivalTree = root => {
    const stack = [root],
        value = root.val;
    
    while (stack.length){
        let node = stack.pop();
        let left = node.left,
            right = node.right;
        
        if (right){
            if (right.val != value){
                return false;
            }
            stack.push(right);
        }
        if (left){
            if (left.val != value){
                return false;
            }
            stack.push(left);
        }
    }
    return true;
};
