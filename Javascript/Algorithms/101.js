let isSymmetric = function(root) {
  let left = root.left, right = root.right;
  if (!left && !right) return true;
  if (left == null) return false;
  if (right == null) return false;

  // Use a stack for each subtree.
  const sleft = [left], sright = [right];
  while (sleft.length || sright.length) {
    let [left, right] = [sleft.pop(), sright.pop()];
    // Value check.
    if (left.val != right.val) return false;

    // grab children for each
    let lleft = left.left, lright = left.right, rleft = right.left,
        rright = right.right;
    // and append them symmetrically.
    if (lleft && rright) {
      sleft.push(lleft);
      sright.push(rright);
    } else {
      // One of them is None. If not both,
      // we got a mismatch.
      if (lleft != rright) return false;
    }
    if (lright && rleft) {
      sleft.push(lright);
      sright.push(rleft);
    } else {
      if (lright != rleft) return false;
    }
  }
  return sleft.length == sright.length;
};