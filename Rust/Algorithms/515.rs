use std::cell::RefCell;
use std::cmp;
use std::rc::Rc;

impl Solution {
    pub fn largest_values(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<i32> {
        let mut maxes = vec![];

        if root.is_none() {
            return maxes;
        }

        let mut stack = vec![(root.unwrap(), 0)];
        while stack.len() > 0 {
            let (node, level) = stack.pop().unwrap();
            let node = Rc::try_unwrap(node).unwrap().into_inner();
            if level >= maxes.len() {
                maxes.push(node.val);
            } else {
                maxes[level] = cmp::max(maxes[level], node.val);
            }
            if let Some(left) = node.left {
                stack.push((left, level + 1));
            }
            if let Some(right) = node.right {
                stack.push((right, level + 1));
            }
        }
        maxes
    }
}
