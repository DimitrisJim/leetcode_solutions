use std::rc::Rc;
use std::cell::RefCell;

use std::rc::Rc;
use std::cell::RefCell;

/// Use this in playground to mess around with how you can 
/// get the commented out part of range_sum_bst to work. 
/// 
/// Basically, don't know how to assign root = root.left when 
/// trying to reduce the root to a better position.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}
 
impl TreeNode {
  #[inline]
  pub fn new(val: i32, l: Option<i32>, r: Option<i32>) -> Self {
    let (left, right) = match (l, r) {
        (Some(x), Some(y)) => {
            (
                Some(Rc::new(RefCell::new(TreeNode::new(x, None, None)))), 
                Some(Rc::new(RefCell::new(TreeNode::new(y, None, None))))
            )
        }
        (None, Some(y)) => {
            (
                None, 
                Some(Rc::new(RefCell::new(TreeNode::new(y, None, None))))
            )
        }
        (Some(x), None) =>{ 
            (
                Some(Rc::new(RefCell::new(TreeNode::new(x, None, None)))), 
                None
            )
        }
        (None, None) => (None, None)
    };
    TreeNode {
      val, left, right
    }
  }
}

impl Solution {
    pub fn inorder(node: Option<&Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        let mut sum = 0;
        let left = &node.expect("The unexpected.").borrow().left;
        if left.is_some() {
            sum += Solution::inorder(left.as_ref(), l, r);
        }
        let val = node.expect("The unexpected").borrow().val;
        if (l <= val) && (val <= r) {
            sum += val;
        }
        
        let right = &node.expect("The unexpected.").borrow().right;
        if right.is_some() {
            sum += Solution::inorder(right.as_ref(), l, r);            
        }
        sum
    }

    pub fn range_sum_bst(mut root: Option<Rc<RefCell<TreeNode>>>, l: i32, r: i32) -> i32 {
        if l == r {
            return l;
        }
        if root.is_none() {
            return 0;
        }

        // We know it's Some now.
        let mut node : Rc<RefCell<TreeNode>> = Rc::clone(&root.expect("The unexpected."));
        let mut rval = node.borrow().val;

        // Can't get this to work yet, unfortunately..
        /*
        while !((l <= rval) && (rval <= r)){
            if l > rval {
                let node = node.borrow().right.as_ref().expect("");
            }
            if rval > r {
                let node = node.borrow().left.as_ref().expect("The unexpected.");                           }
            rval = node.borrow().val;
        }
        */

        if rval == l{
            return rval + Solution::inorder(node.borrow().right.as_ref(), l, r);
        }
        if rval == r {
            return rval + Solution::inorder(node.borrow().left.as_ref(), l, r);
        }

        Solution::inorder(Some(&Rc::clone(&node)), l, r)
    }
}
