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

// Rc<RefCell>> is such a pain.
impl Solution {
    pub fn increasing_bst(
        mut root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut stack: Vec<Option<_>> = Vec::new();
        let mut inorder: Vec<Option<_>> = Vec::new();

        // inorder traversal.
        while stack.len() != 0 || root.is_some() {
            match root.is_some() {
                true => {
                    stack.push(root.clone());
                    // root => root.right
                    root = root.expect("Some").borrow().left.clone()
                }
                false => {
                    root = stack.pop().expect("Some.");
                    // Make left node = None
                    inorder.push(root.clone());
                    root.clone().expect("Some").borrow_mut().left.take();
                    // Make root = root.right
                    root = root.expect("Some").borrow().right.clone()
                }
            }
        }
        // reattach nodes.
        for i in (1..inorder.len()).rev() {
            inorder[i - 1].as_ref().expect("Some.").borrow_mut().right = inorder[i].clone();
        }
        inorder[0].clone()
    }
}
