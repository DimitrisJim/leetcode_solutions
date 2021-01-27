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
let sumEvenGrandparent = root => {
    let traverse_sum = (node, pval) => {
        let {val, left, right} = node,
            sum = 0;
        
        // If left, add left val to sum if pval
        // is even and add sum from recursing on
        // left subtree.
        // Similarly for right.
        if (left){
            if (!(pval & 1))
                sum += left.val;
            sum += traverse_sum(left, val);
        }
        if (right){
            if (!(pval & 1))
                sum += right.val;
            sum += traverse_sum(right, val);
        }
        return sum;
    }
    let {val, left, right} = root,
        sum = 0;
    if (left)
        sum += traverse_sum(left, val);
    if (right)
        sum += traverse_sum(right, val);
    return sum;
};
