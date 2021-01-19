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
 * @return {number[][]}
 */
let levelOrderBottom = root => {
    if (!root) {
        return [];
    }
    let level = 0,
        d = [[root, 0]],
        result = [[]];
        
    while (d.length > 0) {
        let [n, lvl] = d.pop();
        let {val, left, right} = n;
        if (right){
            d.push([right, lvl + 1]);
        }
        if (left) {
            d.push([left, lvl + 1]);
        }
        
        // Need to check if we have another level.
        if (lvl > level) {
            level = lvl;
            result.push([]);
        }
        result[lvl].push(val);
    }
    return result.reverse();    
};
