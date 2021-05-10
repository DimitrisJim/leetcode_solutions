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
    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if (root.is_none()){
            return vec![];
        }
        let mut values = vec![];
        let mut stack = vec![root.unwrap()];
        while (stack.len() > 0) {
            let node = Rc::try_unwrap(stack.pop().unwrap()).unwrap().into_inner();

            values.push(node.val);
            // Push left second so we pop it first.
            if let Some(right) = node.right {
                stack.push(right);
            }
            if let Some(left) = node.left {
                stack.push(left);
            }
        }    
        values
    }
}