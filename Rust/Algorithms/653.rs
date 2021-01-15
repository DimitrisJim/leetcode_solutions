e std::collections::HashSet;
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        let mut seen = HashSet::new();
        let mut q = vec![root.unwrap()];
        
        while q.len() > 0 {
            // We know we can unwrap since we are the only reference.
            let n = Rc::try_unwrap(q.pop().unwrap()).ok().unwrap().into_inner();
            let (val, left, right) = (n.val, n.left, n.right);
            
            if seen.contains(&(k - val)) {
                return true;
            } else {
                seen.insert(val);
            }
            
            if let Some(left_node) = left {
                q.push(left_node);
            }
            if let Some(right_node) = right {
                q.push(right_node);
            }
        }
        false
    }
}
