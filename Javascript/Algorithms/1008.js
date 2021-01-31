/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @return {TreeNode}
 */
let bstFromPreorder = preorder => {
    const build = (start, end) => {
        if (start == end)
            return null;
            
        let val = preorder[start];
        let max_min = start + 1;
        // find max val smaller than node.val (left subtree)
        while (max_min < end && preorder[max_min] < val) max_min++;
                
        // fill left with vals < node.val and right with vals > node.val
        return new TreeNode(
            val,
            build(start + 1, max_min),
            build(max_min, end)
        );
    }
    return build(0, preorder.length);
};
