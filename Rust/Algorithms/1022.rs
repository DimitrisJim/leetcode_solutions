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
    pub fn sum_root_to_leaf(mut root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // Append pairs since we can't change the root.val.
        let mut stack = vec![root];
        let mut paths = vec![];

        while !stack.is_empty() {
            let mut node = stack.pop().expect("stack should never be empty here.");
            // Completely unwrap our node.
            let inode = Rc::try_unwrap(node.expect("We only add Some nodes to stack."))
                .ok()
                .unwrap()
                .into_inner();

            // Add to paths if we have no children.
            if inode.left.is_none() && inode.right.is_none() {
                paths.push(inode.val);
                continue;
            }
            // Push right node with updated str val.
            if inode.right.is_some() {
                let val = inode
                    .right
                    .clone()
                    .expect("Right subnode has been checked with is_some.")
                    .borrow()
                    .val;
                inode
                    .right
                    .clone()
                    .expect("Right subnode has been checked with is_some.")
                    .borrow_mut()
                    .val = (inode.val << 1) | val;
                stack.push(inode.right)
            }
            // Push left node with updated str val.
            if inode.left.is_some() {
                let val = inode
                    .left
                    .clone()
                    .expect("Left subnode has been checked with is_some.")
                    .borrow()
                    .val;
                inode
                    .left
                    .clone()
                    .expect("Right subnode has been checked with is_some.")
                    .borrow_mut()
                    .val = (inode.val << 1) | val;
                stack.push(inode.left)
            }
        }
        paths.iter().sum()
    }
}
