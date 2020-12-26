let trimBST = (root, low, high) => {
    // Use closure to update root and re-use low, high.
    let trimmer = (node, parent = null) => {
        if (node == null){
            return;
        }
        const value = node.val,
              left = node.left,
              right = node.right;
        
        // If we're not in range, trim stuff.
        if (value < low || value > high){
            // Unless we're at root level, we need to
            // re-adjust the root here.
            if (parent == null) {
                if (value < low){
                    parent = right;
                    root = right;
                } else {
                    parent = left;
                    root = left;
                }
                // return needed.
                return trimmer(parent);
            }
            // Trim branches off.
            if (value < low){
                parent.left = right;
                trimmer(right, parent);
            } else {
                parent.right = left;
                trimmer(left, parent);
            }
        // node is in range, recurse on children.
        } else {
            trimmer(left, node);
            trimmer(right, node);
        }
    };
    trimmer(root);
    return root;
};
