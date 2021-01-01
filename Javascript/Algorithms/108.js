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
let sortedArrayToBST = nums => {
    const build_tree = (left, right) => {
        if (left == right){
            return null;
        }
        const mid = Math.floor((left + right) / 2);
        let node = new TreeNode(nums[mid]);
        
        // fill left, right
        node.left = build_tree(left, mid);
        node.right = build_tree(mid + 1, right);
        
        return node;
    }
    return build_tree(0, nums.length);
};
