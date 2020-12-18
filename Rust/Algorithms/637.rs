use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn average_of_levels(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<f64> {
        let mut q = VecDeque::new();
        let mut res = Vec::new();
        let (mut values, mut numNodes) = (0i64, 0);
        q.push_back(root);
        q.push_back(None); // marker.

        loop {
            match q.pop_front().unwrap() {
                None => {
                    // Reached end.
                    if numNodes == 0 {
                        break;
                    }
                    res.push((values as f64) / (numNodes as f64));
                    q.push_back(None); // place marker back.
                                       // Set counters back to zero.
                    values = 0;
                    numNodes = 0;
                    continue;
                }
                Some(node) => {
                    let inode =
                        Rc::try_unwrap(node).ok().unwrap().into_inner();
                    values += inode.val as i64;
                    numNodes += 1;
                    if inode.left.is_some() {
                        q.push_back(inode.left);
                    }
                    if inode.right.is_some() {
                        q.push_back(inode.right);
                    }
                }
            }
        }
        res
    }
}
