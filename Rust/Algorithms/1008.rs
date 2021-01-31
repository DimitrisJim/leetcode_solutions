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
    pub fn bst_from_preorder(
        preorder: Vec<i32>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        fn build(
            vals: &Vec<i32>,
            start: usize,
            end: usize,
        ) -> Option<Rc<RefCell<TreeNode>>> {
            if (start == end) {
                return None;
            }
            let val = vals[start];
            let mut max_min = start + 1;
            // find max val smaller than node.val (left subtree)
            while (max_min < end && vals[max_min] < val) {
                max_min += 1;
            }

            // fill left with vals < node.val and right with vals > node.val
            Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: build(vals, start + 1, max_min),
                right: build(vals, max_min, end),
            })))
        }
        build(&preorder, 0, preorder.len())
    }
}
