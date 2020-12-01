use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let value = root.as_ref().unwrap().borrow().val;
        let mut stack = vec![root];

        while stack.len() > 0 {
            let node = Rc::try_unwrap(stack.pop().flatten().unwrap())
                .ok()
                .unwrap()
                .into_inner();
            let left = node.left;
            let right = node.right;

            if right.is_some() {
                if right.as_ref().unwrap().borrow().val != value {
                    return false;
                }
                stack.push(right);
            }

            if left.is_some() {
                if left.as_ref().unwrap().borrow().val != value {
                    return false;
                }
                stack.push(left);
            }
        }
        true
    }
}
