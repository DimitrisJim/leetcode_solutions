/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
let deepestLeavesSum = root => {
    let l_sum = 0, depth = 0;
    let traverse = (node, d) => {
        let {val, left, right} = node;

        if (!left && !right){
            if (d > depth){
                depth = d;
                l_sum = val;
            } else if (d == depth)
                l_sum += val;
        } else {
            if (left)
                traverse(left, d + 1);
            if (right)
                traverse(right, d + 1);
        }
    }
    traverse(root, 0)
    return l_sum;    
};
