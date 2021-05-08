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
    pub fn right_side_view(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<i32> {
        if root.is_none() {
            return vec![];
        }

        let root = Rc::try_unwrap(root.unwrap()).unwrap().into_inner();
        let mut nodes = vec![root.val];
        let mut stack = vec![(root, 0)];

        while stack.len() > 0 {
            // We know it's Some.
            let pair = stack.pop().unwrap();
            let node = pair.0;
            let level = pair.1;

            // Push the first node we encounter on next level (which
            // we know due to our pushing on the stack, will be the
            // rightmost node in tree.)
            if level >= nodes.len() {
                nodes.push(node.val);
            }

            // Push right *last*, that way we see it *first*.
            if let Some(left) = node.left {
                stack.push((
                    Rc::try_unwrap(left).unwrap().into_inner(),
                    level + 1,
                ));
            }
            if let Some(right) = node.right {
                stack.push((
                    Rc::try_unwrap(right).unwrap().into_inner(),
                    level + 1,
                ));
            }
        }
        nodes
    }
}
