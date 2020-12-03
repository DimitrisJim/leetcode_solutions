let maxDepth = (root) => {
    const max = Math.max;
    return root? 1 + max(maxDepth(root.left), maxDepth(root.right)): 0;
};
