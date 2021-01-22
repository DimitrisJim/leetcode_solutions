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
    fn get_paths(
        node: Rc<RefCell<TreeNode>>,
        mut prev: String,
        result: &mut Vec<String>,
    ) -> &Vec<String> {
        let n = Rc::try_unwrap(node).unwrap().into_inner();
        let (val, left, right) = (n.val, n.left, n.right);
        // Add val to prev.
        if prev.len() != 0 {
            prev.push_str("->");
        }
        prev.push_str(&val.to_string());

        // Reached leaf, add to result.
        if left.is_none() && right.is_none() {
            result.push(prev);
            return result;
        }

        if let Some(l) = left {
            Solution::get_paths(l, prev.clone(), result);
        }
        if let Some(r) = right {
            Solution::get_paths(r, prev, result);
        }
        return result;
    }

    pub fn binary_tree_paths(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<String> {
        if let Some(node) = root {
            // Similar to clone afaict.
            return Solution::get_paths(
                node,
                String::from(""),
                &mut vec![],
            )
            .to_owned();
        }
        vec![]
    }
}
