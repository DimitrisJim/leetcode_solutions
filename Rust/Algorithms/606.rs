use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    fn preorder(n: Rc<RefCell<TreeNode>>) -> String {
        let n = Rc::try_unwrap(n).unwrap().into_inner();
        let mut s = n.val.to_string();
        match n.left {
            Some(left) => {
                s.push('(');
                s.push_str(&Solution::preorder(left));
                s.push(')');
            }
            None => {
                if n.right.is_some() {
                    s.push_str("()");
                }
            }
        }
        if let Some(right) = n.right {
            s.push('(');
            s.push_str(&Solution::preorder(right));
            s.push(')');
        }
        s
    }

    pub fn tree2str(t: Option<Rc<RefCell<TreeNode>>>) -> String {
        if let Some(node) = t {
            return Solution::preorder(node);
        }
        String::from("")
    }
}
