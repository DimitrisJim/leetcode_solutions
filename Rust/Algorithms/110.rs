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
use std::cmp::max;
use std::collections::HashMap;
use std::rc::Rc;

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // Need it as *mut TreeNode since we cant Hash RefCells. There must
        // be another way, this way seems too flaky.
        let mut cache = HashMap::new();
        fn height(
            node: Rc<RefCell<TreeNode>>,
            cache: &mut HashMap<*mut TreeNode, i32>,
        ) -> i32 {
            // Check if cache contains node, if so return cached value.
            if cache.contains_key(&node.as_ptr()) {
                return *cache.get(&node.as_ptr()).unwrap();
            }
            // Calculate height, place it in cache and return it.
            let mut max_height = 0;
            if let Some(left) = node.borrow().left.as_ref() {
                max_height = height(left.clone(), cache);
            }
            if let Some(right) = node.borrow().right.as_ref() {
                max_height = max(max_height, height(right.clone(), cache));
            }
            cache.insert(node.as_ptr(), max_height + 1);
            max_height + 1
        }

        fn recurse(
            node: Rc<RefCell<TreeNode>>,
            cache: &mut HashMap<*mut TreeNode, i32>,
        ) -> bool {
            let mut res = true;
            let (mut h1, mut h2) = (0, 0);
            // Find height, result for left,right.
            if let Some(left) = node.borrow().left.as_ref() {
                // cloning refcells should be cheap.
                res = recurse(left.clone(), cache);
                h1 = height(left.clone(), cache);
            }
            if let Some(right) = node.borrow().right.as_ref() {
                res = res && recurse(right.clone(), cache);
                h2 = height(right.clone(), cache);
            }
            // Both must hold (true)
            if !res {
                return false;
            }

            // Height diff must be 0, 1.
            (h1 - h2).abs() <= 1
        }
        if let Some(node) = root {
            recurse(node, &mut cache)
        } else {
            true
        }
    }
}
