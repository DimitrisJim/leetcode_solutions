use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn search_bst(
        root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut root = root;
        while (root.is_some()) {
            // Need to borrow because we return it afterwards.
            // We just need a handle to the val.
            let rval = root.clone().expect("Should not be None").borrow().val;
            if rval == val {
                return root;
            }
            // Unwrap node completely.
            let inode = Rc::try_unwrap(root.expect("Should not be None"))
                .ok()
                .unwrap()
                .into_inner();
            // And assign it to left or right according to match.
            root = match val > rval {
                true => inode.right,
                false => inode.left,
            };
        }
        None
    }
}
