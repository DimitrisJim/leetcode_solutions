let sumOfLeftLeaves = root => {
  let sum = 0;
  // iife. no need to keep it around.
  (function sum_left_leaves(node) {
    const left = node.left, right = node.right;

    if (left) {
      if (!left.left && !left.right)
        sum += left.val;
      else
        sum_left_leaves(left);
    }
    if (right) sum_left_leaves(right);
  })(root)
  return sum;
};