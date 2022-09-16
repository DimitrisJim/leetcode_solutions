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

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn check_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // guaranteed not to be None's
        let node = Rc::try_unwrap(root.unwrap()).unwrap().into_inner();
        let left = Rc::try_unwrap(node.left.unwrap()).unwrap().into_inner();
        let right = Rc::try_unwrap(node.right.unwrap()).unwrap().into_inner();
        
        node.val == left.val + right.val
    }
}