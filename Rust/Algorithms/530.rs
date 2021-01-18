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
    // Dfs traversal, push nodes into res as you see them.
    fn traverse(node: Rc<RefCell<TreeNode>>, res: &mut Vec<i32>) {
        // Unwrap node:
        let n = Rc::try_unwrap(node).unwrap().into_inner();
        if let Some(left) = n.left {
            Solution::traverse(left, res);
        }
        res.push(n.val);
        if let Some(right) = n.right {
            Solution::traverse(right, res);
        }
    }

    pub fn get_minimum_difference(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> i32 {
        let mut v = Vec::new();
        Solution::traverse(root.unwrap(), &mut v);

        // We know at least two nodes, initialize min.
        // then go through v and find min of tree.
        let mut min = v[1] - v[0];
        for i in 2..v.len() {
            let diff = v[i] - v[i - 1];
            if diff < min {
                min = diff;
            }
        }
        min
    }
}
