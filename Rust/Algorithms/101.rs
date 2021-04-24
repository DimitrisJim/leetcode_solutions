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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // Completely unwrap root.
        let root = Rc::try_unwrap(root.unwrap()).unwrap().into_inner();

        if root.left.is_none() && root.right.is_none() {
            return true;
        }
        if root.left.is_none() {
            return false;
        }
        if root.right.is_none() {
            return false;
        }

        let mut sleft = vec![root.left.unwrap()];
        let mut sright = vec![root.right.unwrap()];

        while sleft.len() > 0 || sright.len() > 0 {
            let left =
                Rc::try_unwrap(sleft.pop().unwrap()).unwrap().into_inner();
            let right = Rc::try_unwrap(sright.pop().unwrap())
                .unwrap()
                .into_inner();

            // Check values.
            if left.val != right.val {
                return false;
            }

            // Follow (symmetrically) the children.
            let (lleft, lright) = (left.left, left.right);
            let (rleft, rright) = (right.left, right.right);

            if lleft.is_some() && rright.is_some() {
                sleft.push(lleft.unwrap());
                sright.push(rright.unwrap());
            } else {
                if lleft != rright {
                    return false;
                }
            }

            if lright.is_some() && rleft.is_some() {
                sleft.push(lright.unwrap());
                sright.push(rleft.unwrap());
            } else {
                if lright != rleft {
                    return false;
                }
            }
        }
        sleft.len() == sright.len()
    }
}
