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
use std::collections::VecDeque;

impl Solution {
    pub fn merge_trees(t1: Option<Rc<RefCell<TreeNode>>>, t2: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        // Break early if we have a None.
        match (t1.is_none(), t2.is_none()) {
            (true, true)   => return None,
            (true, false)  => return t2,
            (false, true)  => return t1,
            (false, false) => (),
        }
        
        // We know strong count is 1. Remove Rc with try_unwrap and 
        // then remove RefCell with into_inner. Got TreeNodes now.
        let lNode = Rc::try_unwrap(t1.expect("")).ok().unwrap().into_inner();
        let rNode = Rc::try_unwrap(t2.expect("")).ok().unwrap().into_inner();
        // Create root by adding vals.
        let root = Some(Rc::new(RefCell::new(TreeNode::new(lNode.val + rNode.val))));
        
        // Deque for storing elements.
        let mut q = VecDeque::new();
        q.push_front([
            root.clone(), lNode.left, rNode.left, lNode.right, rNode.right
        ]);
        
        while !q.is_empty() {
            let [root, ll, rl, lr, rr] = q.pop_back().expect("Queue shouldn't be holding None values.");
            // Remember to always take root by ref!
            match (ll, rl) {
                // Both nodes are valid. Create new node and add it to tree.
                (Some(ll), Some(rr)) => {
                    // Remove Rc and RefCell.
                    let left = Rc::try_unwrap(ll).ok().unwrap().into_inner();
                    let right = Rc::try_unwrap(rr).ok().unwrap().into_inner();
                    // Create node, clone for root to hold. 
                    let node = Rc::new(RefCell::new(TreeNode::new(left.val + right.val)));
                    root.as_ref().expect("").borrow_mut().left = Some(node.clone());
                    // Push new nodes onto queue.
                    q.push_front([
                        Some(node), left.left, right.left, left.right, right.right
                    ])
                },
                // New node has value of left subtree or 
                // New node has value of right subtree => Create Node, add children.
                (Some(node), None) | (None, Some(node)) => {
                    // Remove Rc and RefCell.
                    let node = Rc::try_unwrap(node).ok().unwrap().into_inner();
                    let mut left = TreeNode::new(node.val);
                    left.left = node.left;
                    left.right = node.right;
                    root.as_ref().expect("").borrow_mut().left = Some(Rc::new(RefCell::new(left)));
                },
                // Both nodes are empty. Left subtree empty.
                (None, None) => {
                    root.as_ref().expect("").borrow_mut().left = None
                }
            }
            match (lr, rr){
                // Both nodes are valid. Create new node and add it to tree.
                (Some(lr), Some(rr)) => {
                    let left = Rc::try_unwrap(lr).ok().unwrap().into_inner();
                    let right = Rc::try_unwrap(rr).ok().unwrap().into_inner();
                    // Create node, clone for root to hold. 
                    let node = Rc::new(RefCell::new(TreeNode::new(left.val + right.val)));
                    root.as_ref().expect("").borrow_mut().right = Some(node.clone());
                    // push new nodes onto queue.
                    q.push_front([
                        Some(node), left.left, right.left, left.right, right.right
                    ])
                },
                // New node has value of left subtree or 
                // New node has value of right subtree => Create Node, add children.
                (Some(node), None) | (None, Some(node)) => {
                    let node = Rc::try_unwrap(node).ok().unwrap().into_inner();
                    let mut right = TreeNode::new(node.val);
                    right.left = node.left;
                    right.right = node.right;
                    root.as_ref().expect("").borrow_mut().right = Some(Rc::new(RefCell::new(right)));
                },
                // Both nodes are empty. Right subtree empty.
                (None, None) => {
                    root.as_ref().expect("").borrow_mut().right = None
                }
            }
        }
        root
    }
}
