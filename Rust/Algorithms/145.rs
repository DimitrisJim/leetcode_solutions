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
    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        fn traverse(node: Rc<RefCell<TreeNode>>, values: &mut Vec<i32>) {
            let node = Rc::try_unwrap(node).unwrap().into_inner();
            
            if let Some(left) = node.left {
                traverse(left, values);
            }
            if let Some(right) = node.right {
                traverse(right, values);
            }
            values.push(node.val);
        }
        let mut values = vec![];
        if let Some(node) = root {
            traverse(node, &mut values);
        }
        values
    }
}