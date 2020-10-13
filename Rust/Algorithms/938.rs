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
use std::rc::Rc;
use std::cell::RefCell;


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
        /*
        // We know it's Some now.
        let mut node = &root;
        let mut rval = node.as_ref().expect("").borrow().val;
        
        while !((l <= rval) && (rval <= r)){
            if l > rval {
                node = &node.as_ref().expect("The unexpected").borrow().right;
            }
            if rval > r {
                node = &node.as_ref().expect("The unexpected").borrow().left;
            }
            rval = node.as_ref().expect("The unexpected.").borrow().val;
        }
        
        if rval == l{
            return rval + Solution::inorder(node.as_ref(), l, r);
        }
        if rval == r {
            return rval + Solution::inorder(node.as_ref(), l, r);
        }
        */
        Solution::inorder(root.as_ref(), l, r)
    }
}
