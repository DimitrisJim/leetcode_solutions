// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // Did not know I could have local functions. Recursive closures seem to be
        // a tricky issue so just pass values by mutable reference.
        fn traverse_sum(
            node: Rc<RefCell<TreeNode>>,
            current_depth: i32,
            max_depth: &mut i32,
            sum: &mut i32,
        ) {
            let n = Rc::try_unwrap(node).unwrap().into_inner();

            // Alter sum and max_depth only in the case where both children
            // are None's and depth is larger or equal.
            match (n.left, n.right) {
                (Some(left), Some(right)) => {
                    traverse_sum(left, current_depth + 1, max_depth, sum);
                    traverse_sum(right, current_depth + 1, max_depth, sum);
                }
                (Some(left), None) => {
                    traverse_sum(left, current_depth + 1, max_depth, sum);
                }
                (None, Some(right)) => {
                    traverse_sum(right, current_depth + 1, max_depth, sum);
                }
                (None, None) => {
                    if current_depth > *max_depth {
                        *sum = n.val;
                        *max_depth = current_depth;
                    } else if current_depth == *max_depth {
                        *sum += n.val;
                    }
                }
            }
        }
        let (mut sum, mut max_depth) = (0, 0);
        traverse_sum(root.unwrap(), 0, &mut max_depth, &mut sum);
        sum
    }
}
