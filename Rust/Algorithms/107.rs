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
    pub fn level_order_bottom(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<Vec<i32>> {
        if root.is_none() {
            return vec![];
        }
        let mut level = 0;
        let mut d = vec![(root.unwrap(), 0)];
        let mut result = vec![vec![]];

        while d.len() > 0 {
            let (n, lvl) = d.pop().unwrap();
            let node = Rc::try_unwrap(n).unwrap().into_inner();
            if let Some(right) = node.right {
                d.push((right, lvl + 1));
            }
            if let Some(left) = node.left {
                d.push((left, lvl + 1));
            }

            // Need to check if we have another level.
            if lvl > level {
                level = lvl;
                result.push(vec![]);
            }
            result[lvl].push(node.val);
        }
        result.into_iter().rev().collect()
    }
}
