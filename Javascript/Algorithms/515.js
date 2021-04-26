var largestValues = function(root) {
  const maxes = [];
  if (!root) return maxes
    const stack = [[root, 0]]

        while (stack.length) {
      let [node, level] = stack.pop();

      // first time reaching this level]
      // append directly.
      if (level >= maxes.length)
        maxes.push(node.val);
      else
        // update maxes if node.val is larger.
        maxes[level] = Math.max(node.val, maxes[level]);

      let [left, right] = [node.left, node.right];
      if (left) stack.push([left, level + 1]);
      if (right) stack.push([right, level + 1]);
    }
  return maxes
};