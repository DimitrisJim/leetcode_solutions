use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() {
            return 0;
        }
        let mut min_depth = 1000000;
        let mut stack = vec![(root.unwrap(), 1)];
        
        while stack.len() > 0 {
            let (node, depth) = stack.pop().unwrap();
            
            if depth >= min_depth {
                continue;
            }
            
            // Completely unwrap node.
            let node = Rc::try_unwrap(node).unwrap().into_inner();
            if node.left.is_none() && node.right.is_none() {
                min_depth = depth;
            }
            if let Some(left) = node.left {
                stack.push((left, depth + 1));
            }
            if let Some(right) = node.right {
                stack.push((right, depth + 1));
            }
        }
        min_depth
    }
}