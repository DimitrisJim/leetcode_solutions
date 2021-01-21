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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if q.is_none() && p.is_none() {
            return true;
        }
        if (q.is_none() && p.is_some()) || (q.is_some() && p.is_none()) {
            return false;
        }

        let mut s1 = vec![p.unwrap()];
        let mut s2 = vec![q.unwrap()];

        while s1.len() > 0 && s2.len() > 0 {
            let n1 =
                Rc::try_unwrap(s1.pop().unwrap()).unwrap().into_inner();
            let n2 =
                Rc::try_unwrap(s2.pop().unwrap()).unwrap().into_inner();

            let (n1val, n1left, n1right) = (n1.val, n1.left, n1.right);
            let (n2val, n2left, n2right) = (n2.val, n2.left, n2.right);

            // Bail if values are different.
            if (n1val != n2val) {
                return false;
            }
            // Bail early if one is None and the other isn't
            match n1left {
                Some(left1) => {
                    if n2left.is_none() {
                        return false;
                    }
                    s1.push(left1);
                    s2.push(n2left.unwrap());
                }
                None => {
                    if let Some(_) = n2left {
                        return false;
                    }
                }
            }
            match n1right {
                Some(right1) => {
                    if n2right.is_none() {
                        return false;
                    }
                    s1.push(right1);
                    s2.push(n2right.unwrap());
                }
                None => {
                    if let Some(_) = n2right {
                        return false;
                    }
                }
            }
        }

        // We still have nodes in one of the vectors.
        if s1.len() > 0 || s2.len() > 0 {
            false
        } else {
            true
        }
    }
}
