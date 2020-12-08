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
    fn invert(node: &mut Option<Rc<RefCell<TreeNode>>>) {
        if node.is_none() {
            return;
        }
        // Swap (literal pain in the ass.)
        let left = node.clone().unwrap().borrow().left.clone();
        let right = node.clone().unwrap().borrow().right.clone();

        // For both cases: If value replacing is not None, call
        // replace on the Option being replaced and place the
        // Rc<RefCell<_>> replacement .
        // If None, replace with None.
        match right {
            Some(value) => {
                node.clone().unwrap().borrow_mut().left.replace(value);
            }
            None => {
                node.clone().unwrap().borrow_mut().left = None;
            }
        }
        match left {
            Some(value) => {
                node.clone().unwrap().borrow_mut().right.replace(value);
            }
            None => {
                node.clone().unwrap().borrow_mut().right = None;
            }
        }

        // Now we must recurse
        Solution::invert(&mut node.clone().unwrap().borrow().left.clone());
        Solution::invert(
            &mut node.clone().unwrap().borrow().right.clone(),
        );
    }

    pub fn invert_tree(
        mut root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        Solution::invert(&mut root);
        return root;
    }
}
