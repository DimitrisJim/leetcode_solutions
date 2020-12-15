/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */

let next_leaf = stack => {
    while (stack.length){
        let node = stack.pop();
        // If we're a leaf, return val.
        if (!node.left && !node.right){
            return node.val;
        }
        // Add children:
        if (node.right){
            stack.push(node.right);
        }
        if (node.left){
            stack.push(node.left);
        }
    }
    return -1;
}

var leafSimilar = function(root1, root2) {
    const s1 = [root1],
          s2 = [root2];
    let res = false;
    
    while (1){
        const l1 = next_leaf(s1),
              l2 = next_leaf(s2);
        if (l1 != l2){
            break;
        }
        if (l1 == -1 && l2 == -1){
            res = true;
            break;
        }
    }
    return res;
};
