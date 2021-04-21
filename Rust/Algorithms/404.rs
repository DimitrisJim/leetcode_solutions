use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn sum_left_leaves(node: TreeNode, sum: &mut i32) {\
            if let Some(left) = node.left {
                // Unwrap completely (get TreeNode) and check if its a
                // leaf. If so, add value, if not, traverse.
                let left = Rc::try_unwrap(left).unwrap().into_inner();
                if left.left.is_none() && left.right.is_none() {
                    *sum += left.val;
                } else {
                    sum_left_leaves(left, sum);
                }
            }
            if let Some(right) = node.right {
                // Unwrap completely (get TreeNode) and traverse.
                let right = Rc::try_unwrap(right).unwrap().into_inner();
                sum_left_leaves(right, sum);
            }
        }
        let mut sum = 0;
        // We know we have at least one node (root).
        // Not sure if it's a bad idea i'm passing all these by value.
        sum_left_leaves(Rc::try_unwrap(root.unwrap()).unwrap().into_inner(), &mut sum);
        return sum;
    }
}