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
    pub fn bst_to_gst(
        mut root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        // Pass references around and update those.
        fn dfs_inorder(
            node: &mut Option<Rc<RefCell<TreeNode>>>,
            s: &mut i32,
        ) {
            let mut right =
                node.clone().unwrap().borrow_mut().right.clone();
            let mut left = node.clone().unwrap().borrow_mut().left.clone();

            // Go right with ref to right.
            if right.is_some() {
                dfs_inorder(&mut right, s);
            }
            // Update node value with s denoting values accumulated from
            // right traversal.
            node.clone().unwrap().borrow_mut().val += *s;

            // Go left and accumulate values.
            if left.is_some() {
                let mut val = node.clone().unwrap().borrow().val;
                dfs_inorder(&mut left, &mut val);
                // set s to accumulated values.
                *s = val;
            } else {
                // unless there's no left, in which case set it to
                // val of node.
                *s = node.clone().unwrap().borrow().val;
            }
        }

        if root.is_some() {
            let mut s = 0;
            dfs_inorder(&mut root, &mut s);
            root
        } else {
            None
        }
    }
}
