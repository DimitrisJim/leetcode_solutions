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
 * @return {string[]}
 */
let get_paths = (node, prev, result) => {
    let {val, left, right} = node;
    // build path
    if (prev == "")
        prev = `${val}`
    else 
        prev = `${prev}->${val}`;
    
    if (left)
        get_paths(left, prev, result);
    if (right)
        get_paths(right, prev, result);
    // Add path to result when we reach a leaf.
    if (!left && !right){
        result.push(prev);
    }
    return result;
}

let binaryTreePaths = root => {
    if (root){
        return get_paths(root, "", []);
    }
    return [];
};
