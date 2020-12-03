use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn max_depth(node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if node.is_none() {
            return 0;
        }

        let mut mdepth = 0;
        let mut tracker = vec![];
        tracker.push((
            Rc::try_unwrap(node.unwrap()).ok().unwrap().into_inner(),
            0,
        ));
        while tracker.len() != 0 {
            let (node, depth) = tracker.pop().unwrap();
            if depth > mdepth {
                mdepth = depth;
            }
            if let Some(left) = node.left {
                tracker.push((
                    Rc::try_unwrap(left).ok().unwrap().into_inner(),
                    depth + 1,
                ))
            }
            if let Some(right) = node.right {
                tracker.push((
                    Rc::try_unwrap(right).ok().unwrap().into_inner(),
                    depth + 1,
                ))
            }
        }
        mdepth + 1
    }

    pub fn max_depth_rec(node: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if node.is_none() {
            return 0;
        }
        let depth = Solution::max_depth;
        let n = Rc::try_unwrap(node.unwrap()).ok().unwrap().into_inner();
        1 + vec![depth(n.left), depth(n.right)]
            .into_iter()
            .max()
            .unwrap()
    }
}
