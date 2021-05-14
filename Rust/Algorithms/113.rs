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
    pub fn path_sum(
        root: Option<Rc<RefCell<TreeNode>>>,
        target_sum: i32,
    ) -> Vec<Vec<i32>> {
        if root.is_none() {
            return vec![];
        }

        let node = Rc::try_unwrap(root.unwrap()).unwrap().into_inner();
        let value = node.val;
        // node, running value, level
        let mut stack = vec![(node, value, 0)];
        let (mut paths, mut path) = (vec![], vec![]);
        while stack.len() > 0 {
            let pair = stack.pop().unwrap();
            let (node, current_sum, level) = pair;

            if level <= path.len() {
                path.truncate(level);
            }
            path.push(node.val);

            // return true if leaf and sums match.
            if node.left.is_none()
                && node.right.is_none()
                && current_sum == target_sum
            {
                paths.push(path.iter().cloned().collect());
            }
            // else, go through children.
            if let Some(left) = node.left {
                let left = Rc::try_unwrap(left).unwrap().into_inner();
                let sum = current_sum + left.val;
                stack.push((left, sum, level + 1));
            }
            if let Some(right) = node.right {
                let right = Rc::try_unwrap(right).unwrap().into_inner();
                let sum = current_sum + right.val;
                stack.push((right, sum, level + 1));
            }
        }
        paths
    }
}
