/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
let isSameTree = (p, q) => {
    if (p == null && q == null)
        return true;
    if ((p && !q) || (!p && q))
        return false;
    
    const s1 = [p], s2 = [q];
    while (s1.length && s2.length){
        let {val: n1val, left: n1left, right: n1right} = s1.pop();
        let {val: n2val, left: n2left, right: n2right} = s2.pop();
        
        // Bail if values are different.
        if (n1val != n2val)
            return false;
        // Bail early if one is None and the other isn't
        if (n1left) {
            if (!n2left)
                return false;
            s1.push(n1left);
            s2.push(n2left);
        } else {
            if (n2left)
                return false;
        }
        if (n1right) {
            if (!n2right) 
                return false;
            s1.push(n1right);
            s2.push(n2right);
        } else {
            if (n2right)
                return false;
        }
    }
    // If any of s1 or s2 still has elements, false.
    if (s1.length || s2.length)
        return false;
    return true;
};
