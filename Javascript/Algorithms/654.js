/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
let constructMaximumBinaryTree = nums => {
    const build_tree = (start, end) => {
        let max = nums[start], id = start;
        for (let i = start+1; i < end; i++){
            let v = nums[i];
            if (v > max){
                max = v;
                id = i;
            }
        }
    
        // Go left and right:
        let left = null, right = null;
        if (id > start)
            left = build_tree(start, id);
        if (end > id + 1)
            right = build_tree(id+1, end);
    
        return new TreeNode(max, left, right);
    };
    return build_tree(0, nums.length)
};
