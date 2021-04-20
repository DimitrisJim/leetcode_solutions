use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {
            return vec![];
        }
        
        let mut stack = vec![(root.unwrap(), 0)];
        let mut results = vec![];
        
        while stack.len() > 0 {
            let (node, level) = stack.pop().unwrap();
            
            let node = Rc::try_unwrap(node).unwrap().into_inner();
            if (level >= results.len()) {
                results.push(vec![node.val]);
            } else {
                results[level].push(node.val);
            }
            if let Some(right) = node.right {
                stack.push((right, level + 1));
            }
            if let Some(left) = node.left {
                stack.push((left, level + 1));
            }
        }
        results
    }
}