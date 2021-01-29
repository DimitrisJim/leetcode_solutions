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
    pub fn construct_maximum_binary_tree(
        nums: Vec<i32>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        fn build_tree(
            nums: &Vec<i32>,
            start: usize,
            end: usize,
        ) -> Option<Rc<RefCell<TreeNode>>> {
            let (mut val, mut id) = (nums[start], start);
            for i in start + 1..end {
                if nums[i] > val {
                    val = nums[i];
                    id = i;
                }
            }

            let (mut left, mut right) = (None, None);
            if id > start {
                left = build_tree(nums, start, id);
            }
            if end > id + 1 {
                right = build_tree(nums, id + 1, end);
            }
            Some(Rc::new(RefCell::new(TreeNode { val, left, right })))
        }
        build_tree(&nums, 0, nums.len())
    }
}
