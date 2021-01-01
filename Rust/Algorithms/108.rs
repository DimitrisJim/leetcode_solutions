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
    fn build_tree(
        nums: &Vec<i32>,
        low: usize,
        high: usize,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if low == high {
            return None;
        }
        let mid = (low + high) / 2;

        Some(Rc::new(RefCell::new(TreeNode {
            val: nums[mid],
            left: Solution::build_tree(nums, low, mid),
            right: Solution::build_tree(nums, mid + 1, high),
        })))
    }

    pub fn sorted_array_to_bst(
        nums: Vec<i32>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        Solution::build_tree(&nums, 0, nums.len())
    }
}
